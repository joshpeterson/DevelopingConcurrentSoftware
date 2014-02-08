#ifndef __WORD_COUNTER_H
#define __WORD_COUNTER_H

#include <string>
#include <algorithm>

class word_counter
{
public:
	word_counter() : result(0)
	{
    }

	//For testing purposes

	void debug(int r)
	{
		result = r;
	}

	word_counter(const std::string& word_to_find) : result(0)
    {
		// From http://stackoverflow.com/questions/313970/stl-string-to-lower-case
		// which used http://notfaq.wordpress.com/2007/08/04/cc-convert-string-to-upperlower-case/

		std::string temp = word_to_find;
		std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
		target_word = temp;
    }

    template <typename IteratorType> void map(IteratorType begin, IteratorType end)
    {
		std::string temp;
		for (IteratorType i = begin; i < end; i++) {
			temp = *i;
			std::transform(temp.begin(), temp.end(), temp.begin(), ::toupper);
			if (temp == target_word) result++;
		}
    }

    void reduce(const word_counter& other)
    {
		this->result += other.result;
    }

    int get_count() const
    {
        return result;
    }

private:
	int result;
	std::string target_word;

};

#endif // __WORD_COUNTER_H