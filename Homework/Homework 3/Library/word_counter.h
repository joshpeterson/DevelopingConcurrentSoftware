#ifndef __WORD_COUNTER_H
#define __WORD_COUNTER_H

#include <string>

class word_counter
{
public:
    word_counter() : count_(0)
    {
    }

    word_counter(const std::string& word_to_find) : word_to_find_(word_to_find), count_(0)
    {
    }

    template <typename IteratorType> void map(IteratorType begin, IteratorType end)
    {
        for (auto i = begin; i != end; ++i)
        if (case_insensitive_equals(word_to_find_,*i))
                ++count_;
    }

    void reduce(const word_counter& other)
    {
        count_ += other.get_count();
    }

    int get_count() const
    {
        return count_;
    }

private:
    std::string word_to_find_;
    int count_;

    bool case_insensitive_equals(const std::string& left, const std::string& right)
    {
        if (left.length() != right.length())
            return false;

        for (size_t i = 0; i < left.length(); ++i)
            if (tolower(left[i]) != tolower(right[i]))
                return false;

       return true;
    }
};

#endif // __WORD_COUNTER_H