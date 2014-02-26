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
    const std::string word_to_find_;
    const std::vector<std::string> strings_to_search_;
    int count_;

    bool mpi_word_counter::case_insensitive_equals(const std::string& left, const std::string& right);
};

#endif // __MPI_WORD_COUNTER_H