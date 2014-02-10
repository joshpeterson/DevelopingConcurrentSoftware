#ifndef __WORD_COUNTER_H
#define __WORD_COUNTER_H

#include <string>

class word_counter
{
public:
	word_counter() : word_counter("")
    {
    }

	word_counter(const std::string& word_to_find) 
    {
		word = word_to_find;
		count = 0;
    }

    template <typename IteratorType> void map(IteratorType begin, IteratorType end)
    {
		for (IteratorType it = begin; it != end; it++)
		{
			//std::cout << (*it) << std::endl;
			if (_stricmp((*it).c_str(), word.c_str()) == 0) count++;
		}
    }

    void reduce(const word_counter& other)
    {
		count += other.get_count();
    }

    int get_count() const
    {
        return count;
    }
private:
	std::string word;
	int count;
};

#endif // __WORD_COUNTER_H