#include <vector>
#include <mutex>

#ifndef __THREAD_SAFE_VECTOR_H
#define __THREAD_SAFE_VECTOR_H

template <typename T, typename M>
class thread_safe_vector
{
public:
    void push_back(T value)
    {
		std::lock_guard<M>lock(mutex1);		//Vector locked, no other threads can now use the vector
		vector1.push_back(value);
		std::lock_guard<M>unlock(mutex1);	//Vector unlocked, other threads can now use the vector
		return;
    }

    T at(int index) const
    {
		std::lock_guard<M>lock(mutex1);
		T temp = vector1[index];
		std::lock_guard<M>unlock(mutex1);
		return temp;
    }

    int size() const
    {
		std::lock_guard<M>lock(mutex1);
		T temp = vector1.size();
		std::lock_guard<M>unlock(mutex1);
		return temp;
    }
	
private:
//	T position[1000];
	std::vector<T> vector1;
	mutable M mutex1;
//	int Counter = 0;
};

#endif //__THREAD_SAFE_VECTOR_H