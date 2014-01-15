#ifndef __THREAD_SAFE_VECTOR_H
#define __THREAD_SAFE_VECTOR_H

#include <vector>
#include <mutex>

template <typename T, typename MutexType>
class thread_safe_vector_
{
public:
    void push_back(T value)
    {
        std::lock_guard<MutexType> guard(mutex_);
        vector_.push_back(value);
    }

    T at(int index) const
    {
        std::lock_guard<MutexType> guard(mutex_);
        return vector_.at(index);
    }

    int size() const
    {
        std::lock_guard<MutexType> guard(mutex_);
        return vector_.size();
    }
private:
    std::vector<T> vector_;
    mutable MutexType mutex_;
};

template<typename T>
using thread_safe_vector = thread_safe_vector_<T, std::mutex>;

#endif //__THREAD_SAFE_VECTOR_H