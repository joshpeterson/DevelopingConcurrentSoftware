#include "mpi_word_counter.h"

mpi_word_counter::mpi_word_counter(const std::string& word_to_find)
{
}

mpi_word_counter::mpi_word_counter(const mpi_word_counter& other)
{
}


void mpi_word_counter::map(unsigned int begin, unsigned int end)
{
}

unsigned int mpi_word_counter::reduce(unsigned int input)
{
    return 0;
}

int mpi_word_counter::get_count() const
{
    return 0;
}