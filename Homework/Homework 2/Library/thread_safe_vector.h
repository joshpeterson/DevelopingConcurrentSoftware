#ifndef __THREAD_SAFE_VECTOR_H
#define __THREAD_SAFE_VECTOR_H

#include <vector>
#include <mutex>

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
};

#endif //__THREAD_SAFE_VECTOR_H