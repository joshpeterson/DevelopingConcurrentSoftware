#ifndef __MATRIX_H
#define __MATRIX_H

#include <stdexcept>
#include <sstream>
#include <vector>
#include "matrix_element_iterator.h"
#include "matrix_row_iterator.h"
#include "matrix_column_iterator.h"

template <typename T> class matrix_builder;

template<typename ValueType>
class matrix
{
public:
    matrix(std::initializer_list<std::initializer_list<ValueType>> list) : rows_(list.size()), columns_(0),
                                                                           data_()
    {
        int row_number = 1;
        for (auto i = list.begin(); i != list.end(); ++i)
        {
            if (columns_ == 0)
            {
                columns_ = i->size();
            }
            else if (columns_ != i->size())
            {
                std::stringstream message;
                message << "Invalid number of columns in row " << row_number << " - Expected: " 
                        << columns_ << " Actual: " << i->size() << std::endl;
                throw std::invalid_argument(message.str());
            }

            data_.push_back(std::vector<ValueType>(i->begin(), i->end()));

            row_number++;
        }
    }

    matrix(matrix<ValueType>&& other) : rows_(other.rows_), columns_(other.columns_),
                                        data_(std::move(other.data_))
    {
    }

    matrix(size_t rows, size_t columns) : rows_(rows), columns_(columns), data_()
    {
        for (size_t i = 0; i < rows_; ++i)
        {
            data_.push_back(std::vector<ValueType>(columns_));
        }
    }

    size_t rows() const
    {
        return rows_;
    }

    size_t columns() const
    {
        return columns_;
    }

    ValueType operator()(size_t row, size_t column) const
    {
        validate_row(row);
        validate_column(column);

        return data_[row-1][column-1];
    }

    ValueType& operator()(size_t row, size_t column)
    {
        validate_row(row);
        validate_column(column);

        return data_[row-1][column-1];
    }

    matrix_element_iterator<ValueType> begin() const
    {
        return matrix_element_iterator<ValueType>(this);
    }

    matrix_element_iterator<ValueType> end() const
    {
        return matrix_element_iterator<ValueType>();
    }

    matrix_row_iterator<ValueType> row_begin() const
    {
        return matrix_row_iterator<ValueType>(this);
    }

    matrix_row_iterator<ValueType> row_end() const
    {
        return matrix_row_iterator<ValueType>();
    }

    matrix_column_iterator<ValueType> column_begin() const
    {
        return matrix_column_iterator<ValueType>(this);
    }

    matrix_column_iterator<ValueType> column_end() const
    {
        return matrix_column_iterator<ValueType>();
    }

    template <typename T> friend class matrix_builder;
    template <typename T> friend class matrix_row_iterator;
    template <typename T> friend class matrix_column_iterator;

private:
    size_t rows_;
    size_t columns_;
    std::vector<std::vector<ValueType>> data_;

    matrix() : rows_(0), columns_(0), data_()
    {
    }

    matrix(const matrix<ValueType>& other);
    matrix& operator=(const matrix<ValueType>& other);

    void validate_row(size_t row) const
    {
        if (row == 0 || row > rows_)
        {
            std::stringstream message;
            message << "Invalid index - actual number of rows: " << rows_ << " requested index:  "
                    << row << std::endl;
            throw std::invalid_argument(message.str());
        }
    }

    void validate_column(size_t column) const
    {
        if (column == 0 || column > columns_)
        {
            std::stringstream message;
            message << "Invalid index - actual number of columns: " << columns_ << " requested index:  "
                    << column << std::endl;
            throw std::invalid_argument(message.str());
        }
    }
};

#endif // __MATRIX_H
