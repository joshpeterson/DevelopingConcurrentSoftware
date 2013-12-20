#ifndef __MATRIX_COLUMN_ITERATOR_H
#define __MATRIX_COLUMN_ITERATOR_H

#include <iterator>
#include <vector>

template <typename T> class matrix;

template<typename ValueType>
class matrix_column_iterator : public std::iterator<std::forward_iterator_tag, std::vector<ValueType>, ptrdiff_t,
                                                 const std::vector<ValueType>*, const std::vector<ValueType>&>
{
public:
    matrix_column_iterator() : matrix_(NULL), current_column_index_(0)
    {
    }

    explicit matrix_column_iterator(const matrix<ValueType>* matrix) : matrix_(matrix), current_column_index_(0)
    {
    }

    std::vector<ValueType> operator*() const
    {
        std::vector<ValueType> column;
        for (size_t i = 0; i < matrix_->rows_; ++i)
        {
            column.push_back(matrix_->data_[i][current_column_index_]);
        }

        return column;
    }

    const std::vector<ValueType>* operator->() const
    {
        return &(*this);
    }

    matrix_column_iterator& operator++()
    {
        ++current_column_index_;
        if (current_column_index_ > matrix_->columns_ - 1)
        {
            // Signal the end iterator
            matrix_ = NULL;
            current_column_index_ = 0;
        }

        return *this;
    }

    matrix_column_iterator operator++(int)
    {
        matrix_column_iterator previous = *this;
        ++(*this);

        return previous;
    }

    bool equal(const matrix_column_iterator& other) const
    {
        return matrix_ == other.matrix_ && current_column_index_ == other.current_column_index_;
    }

    bool operator==(const matrix_column_iterator& other) const
    {
        return equal(other);
    }

    bool operator!=(const matrix_column_iterator& other) const
    {
        return !equal(other);
    }

private:
    const matrix<ValueType>* matrix_;
    size_t current_column_index_;
};

#endif // __MATRIX_COLUMN_ITERATOR_H
