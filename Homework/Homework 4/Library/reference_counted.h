#ifndef __REFERENCE_COUNTED_H
#define __REFERENCE_COUNTED_H

#include <atomic>
#include <iostream>

template <typename T>
class reference_counted
{
public:
    reference_counted(const T& initial_value) : count_(0)
    {
        value_ = new T;
        *value_ = initial_value;
    }

	//for testing purposes only 
	int _get_count()
	{
		return count_;
	}

	//for testing purposes only
	T _get_value()
	{
		return *value_;
	}

    void add_reference()
    {
        ++count_;
    }

    void release()
    {
        --count_;           // 1
        if (count_ == 0)    // 2
            delete value_;
    }

private:
    T* value_;
    std::atomic<int> count_;
};

#endif // __REFERENCE_COUNTED_H