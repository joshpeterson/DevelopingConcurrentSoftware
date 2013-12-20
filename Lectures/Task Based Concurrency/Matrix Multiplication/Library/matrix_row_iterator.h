#ifndef __MATRIX_ROW_ITERATOR_H
#define __MATRIX_ROW_ITERATOR_H

#include <iterator>
#include <vector>

template <typename T> class matrix;

template<typename ValueType>
class matrix_row_iterator : public std::iterator<std::forward_iterator_tag, std::vector<ValueType>, ptrdiff_t,
                                                 const std::vector<ValueType>*, const std::vector<ValueType>&>
{
public:
    matrix_row_iterator() : matrix_(NULL), current_row_index_(0)
    {
    }

    explicit matrix_row_iterator(const matrix<ValueType>* matrix) : matrix_(matrix), current_row_index_(0)
    {
    }

    std::vector<ValueType> operator*() const
    {
        return matrix_->data_[current_row_index_];
    }

    const std::vector<ValueType>* operator->() const
    {
        return &(*this);
    }

    matrix_row_iterator& operator++()
    {
        ++current_row_index_;
        if (current_row_index_ > matrix_->rows_ - 1)
        {
            // Signal the end iterator
            matrix_ = NULL;
            current_row_index_ = 0;
        }

        return *this;
    }

    matrix_row_iterator operator++(int)
    {
        matrix_row_iterator previous = *this;
        ++(*this);

        return previous;
    }

    bool equal(const matrix_row_iterator& other) const
    {
        return matrix_ == other.matrix_ && current_row_index_ == other.current_row_index_;
    }

    bool operator==(const matrix_row_iterator& other) const
    {
        return equal(other);
    }

    bool operator!=(const matrix_row_iterator& other) const
    {
        return !equal(other);
    }

private:
    const matrix<ValueType>* matrix_;
    size_t current_row_index_;
};

#endif // __MATRIX_ROW_ITERATOR_H
