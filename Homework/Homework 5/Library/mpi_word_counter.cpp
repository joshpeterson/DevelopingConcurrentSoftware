#include "mpi_word_counter.h"

mpi_word_counter::mpi_word_counter(const std::string& word_to_find, const std::vector<std::string>& strings_to_search) :
    word_to_find_(word_to_find), strings_to_search_(strings_to_search), count_(0)
{
}

void mpi_word_counter::map(unsigned int begin, unsigned int end)
{
    for (auto i = begin; i <= end; ++i)
    {
        if (case_insensitive_equals(word_to_find_, strings_to_search_[i]))
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