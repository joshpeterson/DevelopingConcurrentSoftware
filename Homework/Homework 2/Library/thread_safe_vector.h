#ifndef __THREAD_SAFE_VECTOR_H
#define __THREAD_SAFE_VECTOR_H

template <typename T>
class thread_safe_vector
{
public:
    void push_back(T value)
    {
    }

    T at(int index) const
    {
        return T();
    }

    int size() const
    {
        return 0;
    }
};

#endif //__THREAD_SAFE_VECTOR_H