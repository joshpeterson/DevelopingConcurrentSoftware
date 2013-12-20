#ifndef __MATRIX_ELEMENT_ITERATOR_H
#define __MATRIX_ELEMENT_ITERATOR_H

#include <iterator>

template <typename T> class matrix;

template<typename ValueType>
class matrix_element_iterator : public std::iterator<std::forward_iterator_tag, ValueType, ptrdiff_t,
                                                             const ValueType*, const ValueType&>
{
public:
    matrix_element_iterator() : matrix_(NULL), current_row_index_(0), current_column_index_(0)
    {
    }

    explicit matrix_element_iterator(const matrix<ValueType>* matrix) : matrix_(matrix),
                                                                        current_row_index_(0),
                                                                        current_column_index_(0)
    {
    }

    ValueType operator*() const
    {
        return (*matrix_)(current_row_index_+1, current_column_index_+1);
    }

    const ValueType* operator->() const
    {
        return &(*this);
    }

    matrix_element_iterator& operator++()
    {
        ++current_column_index_;
        if (current_column_index_ >= matrix_->columns())
        {
            current_column_index_ = 0;
            ++current_row_index_;
        }

        if (current_row_index_ >= matrix_->rows())
        {
            // Signal the end matrix_element_iterator
            matrix_ = NULL;
            current_row_index_ = 0;
            current_column_index_ = 0;
        }

        return *this;
    }

    matrix_element_iterator operator++(int)
    {
        matrix_element_iterator previous = *this;
        ++(*this);

        return previous;
    }

    bool equal(const matrix_element_iterator& other) const
    {
        return matrix_ == other.matrix_ && current_row_index_ == other.current_row_index_ &&
               current_column_index_ == other.current_column_index_;
    }

    bool operator==(const matrix_element_iterator& other) const
    {
        return equal(other);
    }

    bool operator!=(const matrix_element_iterator& other) const
    {
        return !equal(other);
    }

protected:
    const matrix<ValueType>* matrix_;

private:
    size_t current_row_index_;
    size_t current_column_index_;
};

#endif // __MATRIX_ELEMENT_ITERATOR_H
