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
	//for testing
	std::string get_word();


	//ADDED
private:
	int count;
	std::string word;
	std::vector<std::string> strings_to_search_;
};

#endif // __MPI_WORD_COUNTER_H