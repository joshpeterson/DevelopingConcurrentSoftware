#ifndef __THREAD_SAFE_VECTOR_H
#define __THREAD_SAFE_VECTOR_H
#include<vector>
using std::vector;
#include <stdexcept>
#include<mutex>



template <typename T>
class thread_safe_vector
{
private:
	std::mutex m;
	vector<T> Type;
public:

	void push_back(T value);

	T at(int index) const;

	int size() const;
};


template <class T>
int thread_safe_vector<T>::size() const
{
	return Type.size(); //concurrently acessing or modifying is safe
}

template <class T>
T thread_safe_vector<T>::at(int index) const
{
	//std::lock_guard<std::mutex> lock(m);
	return Type.at(index);
}


template <class T>
void thread_safe_vector<T>::push_back(T value)
{
	std::lock_guard<std::mutex> lock(m);
	Type.push_back(value);
	return;
}

#endif //__THREAD_SAFE_VECTOR_H
