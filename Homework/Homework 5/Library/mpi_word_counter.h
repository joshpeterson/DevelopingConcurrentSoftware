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

	bool equalsSearchTerm(unsigned int index);

private:
	std::vector<std::string> search_body;
	std::string word;
	int count;
};

#endif // __MPI_WORD_COUNTER_H