#include "mpi_word_counter.h"

mpi_word_counter::mpi_word_counter(const std::string& word_to_find, const std::vector<std::string>& strings_to_search)
{
	counter = 0;
	word = word_to_find;
	word_upper = word;
	word_upper[0] = toupper(word[0]);
	word_search = strings_to_search;
}

void mpi_word_counter::map(unsigned int begin, unsigned int end)
{
	for (auto i = begin; i != end; ++i)
	{
		if (word_search.at(i) == word || word_search.at(i) == word_upper)
			++counter;
	}
}

unsigned int mpi_word_counter::reduce(unsigned int input)
{
    return counter += input;
}

int mpi_word_counter::get_count() const
{
    return counter;
}