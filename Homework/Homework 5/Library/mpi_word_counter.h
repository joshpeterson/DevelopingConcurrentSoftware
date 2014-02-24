#ifndef __MPI_WORD_COUNTER_H
#define __MPI_WORD_COUNTER_H

#include <vector>
#include <string>

class mpi_word_counter
{
public:
    mpi_word_counter(const std::string& word_to_find, const std::vector<std::string>& strings_to_search);

    void map(unsigned int begin, unsigned int end);
    unsigned int reduce(unsigned int input);

    int get_count() const;
private:
	int counter;
	std::string word, word_upper;
	std::vector<std::string> word_search;
};

#endif // __MPI_WORD_COUNTER_H