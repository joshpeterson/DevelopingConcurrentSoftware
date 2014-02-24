#include "mpi_word_counter.h"
#include <algorithm>

//2 arg constructor
mpi_word_counter::mpi_word_counter(const std::string& word_to_find, const std::vector<std::string>& strings_to_search)
{
	strings_to_search_ = strings_to_search;
	count = 0;
	word = word_to_find;
	// from:http://stackoverflow.com/questions/313970/stl-string-to-lower-case
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
}

void mpi_word_counter::map(unsigned int begin, unsigned int end)
{
	//std::string temp;

	for (auto i = begin; i < end; ++i)
	{
		//temp = i;
		//std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		//if (word==temp)
		strings_to_search_[i][0] = tolower(strings_to_search_[i][0]);
		if (word == strings_to_search_[i])
			++count;
	}
}




unsigned int mpi_word_counter::reduce(unsigned int input)
{
	count += input;
    return count;
}

int mpi_word_counter::get_count() const
{
    return count;
}

//added:

std::string mpi_word_counter::get_word()
{
	return word;
}