#include "mpi_word_counter.h"

extern std::vector<std::string> gettysburg_address;

mpi_word_counter::mpi_word_counter(const std::string& word_to_find) : word_to_find_(word_to_find), count_(0)
{
}

mpi_word_counter::mpi_word_counter(const mpi_word_counter& other) : word_to_find_(other.word_to_find_), count_(other.count_)
{
}

void mpi_word_counter::map(unsigned int begin, unsigned int end)
{
    for (auto i = begin; i != end; ++i)
    {
        if (case_insensitive_equals(word_to_find_, gettysburg_address[i]))
            ++count_;
    }
}

unsigned int mpi_word_counter::reduce(unsigned int input)
{
    count_ += input;
    return count_;
}

int mpi_word_counter::get_count() const
{
    return count_;
}

bool mpi_word_counter::case_insensitive_equals(const std::string& left, const std::string& right)
{
    if (left.length() != right.length())
        return false;

    for (size_t i = 0; i < left.length(); ++i)
    if (tolower(left[i]) != tolower(right[i]))
        return false;

    return true;
}