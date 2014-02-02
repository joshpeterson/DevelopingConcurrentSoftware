#ifndef __THREAD_SAFE_VECTOR_H
#define __THREAD_SAFE_VECTOR_H

template <typename T>
class thread_safe_vector
{
public:
    void push_back(T value)
    {
		position[Counter] = value;
		Counter++;
		return;
    }

    T at(int index) const
    {
		return position[index];
    }

    int size() const
    {
        return Counter;
    }
	
private:
	T position[1000];
	int Counter = 0;
};

#endif //__THREAD_SAFE_VECTOR_H