#ifndef __THREAD_SAFE_VECTOR_H
#define __THREAD_SAFE_VECTOR_H

#include <vector>
#include <mutex>

<<<<<<< HEAD
template <typename T>
class thread_safe_vector
{
public:
	void push_back(T value)
	{
		std::lock_guard<std::mutex> guard(mutex_);
		v_.push_back(value);
	}

	T at(int index) const
	{
		std::lock_guard<std::mutex> guard(mutex_);
		return v_.at(index);
	}

	int size() const
	{
		std::lock_guard<std::mutex> guard(mutex_);
		return v_.size();
	}

private:
	std::vector<T> v_;
	mutable std::mutex mutex_;
=======
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
>>>>>>> 062c77192f80d862961d77ca50bbebf97c987e57
};

template<typename T>
using thread_safe_vector = thread_safe_vector_<T, std::mutex>;

#endif //__THREAD_SAFE_VECTOR_H