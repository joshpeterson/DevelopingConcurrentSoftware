#ifndef __THREAD_SAFE_VECTOR_H
#define __THREAD_SAFE_VECTOR_H

#include <vector>
#include <mutex>

template <typename T, typename M>
class thread_safe_vector_
{
public:
	// Add a unit to the end of the vector
    void push_back(T value)
    {
		std::lock_guard<M> guard(mutex_);
		vector_.push_back(value);
    }

	// return the item at the index
    T at(int index) const
    {
		std::lock_guard<M> guard(mutex_);

		// Should this throw an invalid argument if the index is out of range?
		// Or should it return false?
		if (vector_.size() <= index) throw std::invalid_argument("Index Out of Range");

		return vector_.at(index);
    }

	// return the size of the vector
    int size() const
    {
		std::lock_guard<M> guard(mutex_);
		return vector_.size();
    }

private:
	std::vector<T> vector_;
	mutable M mutex_;
};

// Allow users to use: thread_safe_vector<typename T>
template <typename T>
using thread_safe_vector = thread_safe_vector_<T, std::mutex>;

#endif //__THREAD_SAFE_VECTOR_H