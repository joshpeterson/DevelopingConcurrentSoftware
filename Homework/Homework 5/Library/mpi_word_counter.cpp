#include "mpi_word_counter.h"
#include <algorithm>

mpi_word_counter::mpi_word_counter(const std::string& word_to_find, const std::vector<std::string>& strings_to_search)
{
	word_copy = word_to_find;
	strings_copy = &strings_to_search;
	std::transform(word_copy.begin(), word_copy.end(), word_copy.begin(), ::tolower);
}

void mpi_word_counter::map(unsigned int begin, unsigned int end)
{
	for (unsigned int i = begin; i < end; i++)
	{
		std::string tmp((*strings_copy)[i]);
		std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
		if (tmp == word_copy)
			count++;
	}
}

unsigned int mpi_word_counter::reduce(unsigned int input)
{
    return count +=input;
}

int mpi_word_counter::get_count() const
{
    return count;
}