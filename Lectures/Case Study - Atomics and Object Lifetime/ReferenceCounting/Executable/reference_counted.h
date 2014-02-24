#ifndef __REFERENCE_COUNTED_H
#define __REFERENCE_COUNTED_H

#include <atomic>
#include <iostream>

template <typename T>
class reference_counted
{
public:
    reference_counted(T initial_value) : count_(0)
    {
        value_ = new T;
        *value_ = initial_value;
    }

    void add_reference()
    {
        ++count_;
    }

    void release(int call_identifier)
    {
        --count_;           // 1
        if (count_ == 0)    // 2
            delete value_;
    }

private:
    T* value_;
    std::atomic<int> count_; //how we know how many are using
};

#endif // __REFERENCE_COUNTED_H