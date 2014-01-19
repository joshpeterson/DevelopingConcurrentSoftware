#ifndef __MPI_WORD_COUNTER_H
#define __MPI_WORD_COUNTER_H

#include <vector>
#include <string>

class mpi_word_counter
{
public:
    mpi_word_counter(const std::string& word_to_find);
    mpi_word_counter(const mpi_word_counter& other);

    void map(unsigned int begin, unsigned int end);
    unsigned int reduce(unsigned int input);

    int get_count() const;
};

#endif // __MPI_WORD_COUNTER_H