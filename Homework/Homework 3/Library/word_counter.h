#ifndef __WORD_COUNTER_H
#define __WORD_COUNTER_H

#include <string>

class word_counter
{
public:
<<<<<<< HEAD
	word_counter() : word_counter("")
    {
    }

	word_counter(const std::string& word_to_find) 
=======
    word_counter() : count_(0)
    {
    }

    word_counter(const std::string& word_to_find) : word_to_find_(word_to_find), count_(0)
>>>>>>> 062c77192f80d862961d77ca50bbebf97c987e57
    {
		word = word_to_find;
		count = 0;
    }

    template <typename IteratorType> void map(IteratorType begin, IteratorType end)
    {
<<<<<<< HEAD
		for (IteratorType it = begin; it != end; it++)
		{
			//std::cout << (*it) << std::endl;
			if (_stricmp((*it).c_str(), word.c_str()) == 0) count++;
		}
=======
        for (auto i = begin; i != end; ++i)
        {
            if (case_insensitive_equals(word_to_find_,*i))
                    ++count_;
        }
>>>>>>> 062c77192f80d862961d77ca50bbebf97c987e57
    }

    void reduce(const word_counter& other)
    {
<<<<<<< HEAD
		count += other.get_count();
=======
        count_ += other.get_count();
>>>>>>> 062c77192f80d862961d77ca50bbebf97c987e57
    }

    int get_count() const
    {
<<<<<<< HEAD
        return count;
=======
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
>>>>>>> 062c77192f80d862961d77ca50bbebf97c987e57
    }
private:
	std::string word;
	int count;
};

#endif // __WORD_COUNTER_H