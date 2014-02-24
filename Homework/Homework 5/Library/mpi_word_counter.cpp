#include "mpi_word_counter.h"
#include <iostream>

mpi_word_counter::mpi_word_counter(const std::string& word_to_find, const std::vector<std::string>& strings_to_search)
{
	word = word_to_find;
	search_body = strings_to_search;
}

void mpi_word_counter::map(unsigned int begin, unsigned int end)
{
	for (auto i = begin; i <= end; i++)
	{
		if (equalsSearchTerm(i)) count++;
	}
}

unsigned int mpi_word_counter::reduce(unsigned int input)
{
    count+=input;
	return count;
}

int mpi_word_counter::get_count() const
{
    return count;
}

bool mpi_word_counter::equalsSearchTerm(unsigned int index)
{
	std::string curString = search_body[index];
	unsigned int size = word.size();

	if (curString.size() != size)
		return false;

	for (unsigned int i = 0; i < size; i++)
		if (tolower(word[i]) != tolower(curString[i]))
			return false;

	return true;
}