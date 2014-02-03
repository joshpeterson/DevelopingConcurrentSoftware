#ifndef __THREAD_SAFE_VECTOR_H
#define __THREAD_SAFE_VECTOR_H

#include <mutex>
#include <vector>

template <typename T>
class thread_safe_vector
{
public:

	// constructor for vector creation
	thread_safe_vector(std::vector<T> vect) : v(vect) { }
	thread_safe_vector() { }

	void push_back(T value)
	{
			std::lock_guard<std::mutex> g(mm);
			v.push_back(value);
	}

    T at(int index) const
	{
		std::lock_guard<std::mutex> g(mm);
		return v.at(index);
    }

    int size() const
    {
		std::lock_guard<std::mutex> g(mm);
		return v.size();
    }

private:
	mutable std::mutex mm;
	std::vector<T> v;
};

#endif //__THREAD_SAFE_VECTOR_H
