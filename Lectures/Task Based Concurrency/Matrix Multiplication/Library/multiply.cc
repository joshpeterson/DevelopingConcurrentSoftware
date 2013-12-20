#include <sstream>
#include <stdexcept>
#include "multiply.h"
#include "matrix.h"
#include "parallel_task.h"

std::shared_ptr<const matrix<double>> multiply::call(std::shared_ptr<const matrix<double>> left, std::shared_ptr<const matrix<double>> right,
                                                     int number_of_threads) const
{
    if (left->columns() != right->rows())
    {
        std::stringstream message;
        message << "The number of columns in the left metrix (" << left->columns()
                << ") is not the same as the number of rows in the right matrix ("
                << right->rows() << ").";
        throw std::invalid_argument(message.str());
    }

    row_multiplier multiplier(left->rows(), right->columns());

    auto task = make_parallel_task(left->row_begin(), right->row_end(), multiplier, right, number_of_threads);
    task.start();
    task.complete();

    return multiplier.get_result();
}

int multiply::number_of_arguments() const
{
    return 2;
}

std::string multiply::get_help() const
{
    return "multiply(A,B) computes the product of two matrices A (m x n) and B (n x p), with A on the left.";
}

row_multiplier::row_multiplier(std::shared_ptr<const matrix<double>> right) : right_(right), task_results_()
{
}

row_multiplier::row_multiplier(size_t rows, size_t columns) : rows_(rows), current_row_(1), columns_(columns), current_column_(1)
{
    result_matrix_ = std::make_shared<matrix<double>>(rows_, columns_);
}

template <typename IteratorType>
void row_multiplier::map(IteratorType begin, IteratorType end)
{
    for (auto row = begin; row != end; ++row)
        for (auto column = right_->column_begin(); column != right_->column_end(); ++column)
            task_results_.push_back(multiply_and_add_vector_elements(*row, *column));
}

void row_multiplier::reduce(const row_multiplier& other)
{
    for (auto result = other.task_results_.begin(); result != other.task_results_.end(); ++result)
    {
        (*result_matrix_)(current_row_, current_column_) = *result;
        if (current_column_ == columns_)
        {
            ++current_row_;
            current_column_ = 1;
        }
        else
        {
            ++current_column_;
        }
    }
}

std::shared_ptr<const matrix<double>> row_multiplier::get_result() const
{
    return result_matrix_;
}

double row_multiplier::multiply_and_add_vector_elements(const std::vector<double>& left, const std::vector<double>& right) const
{
    auto end = left.end();

    auto left_it = left.begin();
    auto right_it = right.begin();

    double result = 0.0;
    while (left_it != end)
    {
        result += *left_it * *right_it;

        ++left_it;
        ++right_it;
    }

    return result;
}

