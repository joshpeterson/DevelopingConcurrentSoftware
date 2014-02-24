#include "mpi_word_counter.h"
#include <iostream>

mpi_word_counter::mpi_word_counter(const std::string& word_to_find, const std::vector<std::string>& strings_to_search)
{
	word_to_find_ = word_to_find;
	sum_ = 0;
	word_to_find_upper = word_to_find;
	word_to_find_upper[0] = toupper(word_to_find[0]);
	strings_to_search_ = strings_to_search;
}

void mpi_word_counter::map(unsigned int begin, unsigned int end)
{
	for (auto i = begin; i <= end; ++i)
	{
		if (strings_to_search_.at(i) == word_to_find_ || strings_to_search_.at(i) == word_to_find_upper) sum_ += 1;
	}
}

unsigned int mpi_word_counter::reduce(unsigned int input)
{
	sum_ += input;
	return sum_;
}

int mpi_word_counter::get_count() const
{
	return sum_;
}