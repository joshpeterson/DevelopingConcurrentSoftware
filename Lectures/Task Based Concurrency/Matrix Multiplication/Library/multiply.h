#ifndef __MULTIPLY_H
#define __MULTIPLY_H

#include <memory>
#include <string>
#include "matrix.h"

class row_multiplier
{
public:
    row_multiplier(std::shared_ptr<const matrix<double>> right);
    row_multiplier(size_t rows, size_t columns);
    template <typename IteratorType> void map(IteratorType begin, IteratorType end);
    void reduce(const row_multiplier& other);

    std::shared_ptr<const matrix<double>> get_result() const;

private:
    std::shared_ptr<const matrix<double>> right_;
    std::vector<double> task_results_;
    size_t rows_;
    size_t current_row_;
    size_t columns_;
    size_t current_column_;
    std::shared_ptr<matrix<double>> result_matrix_;

    double multiply_and_add_vector_elements(const std::vector<double>& left, const std::vector<double>& right) const;
};

class multiply
{
public:
    std::shared_ptr<const matrix<double>> call(std::shared_ptr<const matrix<double>> left, std::shared_ptr<const matrix<double>> right,
                                               int number_of_threads) const;
    int number_of_arguments() const;
    std::string get_help() const;
};

#endif // __MULTIPLY_H
