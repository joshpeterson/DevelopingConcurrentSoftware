#ifndef __WORD_COUNTER_H
#define __WORD_COUNTER_H

#include <string>
#include "parallel_task.h"

#include <iostream>

class word_counter
{
public:
    word_counter()
    {
		counter = 0;
    }

    word_counter(const std::string& word_to_find)
    {
		counter = 0;
		word = word_to_find;
		word_upper = word;
		word_upper[0] = toupper(word[0]);
    }

    template <typename IteratorType> void map(IteratorType begin, IteratorType end)
    {
		for (auto i = begin; i != end; ++i)
		{
			if (*i == word || *i == word_upper)
				++counter;
		}
    }

    void reduce(const word_counter& other)
    {
		counter += other.get_count();
    }

    int get_count() const
    {
        return counter;
    }

private:
	int counter;
	std::string	word, word_upper;
};

#endif // __WORD_COUNTER_H