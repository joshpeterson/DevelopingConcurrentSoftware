#ifndef __WORD_COUNTER_H
#define __WORD_COUNTER_H

#include <string>
#include <algorithm>

class word_counter
{
public:
    word_counter()
    {
		count = 0;
    }

    word_counter(const std::string& word_to_find)
    {
		count = 0;
		// from:http://stackoverflow.com/questions/313970/stl-string-to-lower-case
		word = word_to_find;
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    }

    template <typename IteratorType> void map(IteratorType begin, IteratorType end)
    {
		std::string temp;
		for (IteratorType i = begin; i < end; ++i)
		{
			temp = *i;
			std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			if (word==temp)
				++count;
		}
    }

    void reduce(const word_counter& other)
    {
		//aggregate the results on each partition - puts threads together
		count += other.get_count();
    }

    int get_count() const
    {
		return count;
    }
	

	//for testing only - in tandem with OneArgConstructSucessLower test, ensures that the constructor sucessfully lowercases the finding word
	std::string get_word()
	{
		return word;
	}

private:
	int count;
	std::string word;
};

#endif // __WORD_COUNTER_H