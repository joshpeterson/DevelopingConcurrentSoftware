#ifndef __WORD_COUNTER_H
#define __WORD_COUNTER_H

#include <string>

class word_counter
{
public:
    word_counter()
    {
    }

    word_counter(const std::string& word_to_find)
    {
    }

    template <typename IteratorType> void map(IteratorType begin, IteratorType end)
    {
    }

    void reduce(const word_counter& other)
    {
    }

    int get_count() const
    {
        return 0;
    }
};

#endif // __WORD_COUNTER_H