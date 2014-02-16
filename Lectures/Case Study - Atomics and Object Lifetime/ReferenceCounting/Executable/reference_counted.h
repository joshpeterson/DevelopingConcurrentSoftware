#ifndef __REFERENCE_COUNTED_H
#define __REFERENCE_COUNTED_H

#include <atomic>
#include <iostream>
//#include <chrono>

template <typename T>
class reference_counted
{
public:
    reference_counted(const T& initial_value) : count_(0)
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
        auto count = --count_;           // 1
//		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		if (count == 0)    // 2
		{
//			std::cout << call_identifier;
			delete value_;
		}
    }

private:
    T* value_;
    std::atomic<int> count_;
};

#endif // __REFERENCE_COUNTED_H