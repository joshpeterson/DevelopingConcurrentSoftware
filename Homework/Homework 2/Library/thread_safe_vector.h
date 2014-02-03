#ifndef __THREAD_SAFE_VECTOR_H
#define __THREAD_SAFE_VECTOR_H
#include <vector>
#include <mutex>
template <typename T>
class thread_safe_vector
{
public:

	thread_safe_vector(std::vector<T> vect) : vec(vect) {}
	thread_safe_vector() { };

    void push_back(T value)
    {
		std::lock_guard<std::mutex> g(mm);
		vec.push_back(value);
    }

    T at(int index) const
    {
		std::lock_guard<std::mutex> g(mm);
        return vec.at(index);
    }

    int size() const
    {
		std::lock_guard<std::mutex> g(mm);
		return vec.size();
	}
private:
		mutable std::mutex mm;
		std::vector<T> vec;
};

#endif //__THREAD_SAFE_VECTOR_H