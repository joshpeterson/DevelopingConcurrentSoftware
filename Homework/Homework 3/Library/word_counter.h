#ifndef __WORD_COUNTER_H
#define __WORD_COUNTER_H

#include <string>
#include <memory>

class word_counter
{
public:
	// This simple constructor only needs to set the initial sum to zero.
	word_counter()
    {
		sum_ = 0;
    }

	// This constructor takes a word_to_find string and sets up a word counter instance.
	// to do this, it must set the private variable sum_ to zero, and setup two different
	// versions of the word to be found.  The word_to_find variable receives the all lowercase
	// version of the word, and the word_to_find_upper receives the word to find with a capital
	// first letter.
	word_counter(const std::string& word_to_find) : word_to_find_(word_to_find), sum_(0)
    {
		word_to_find_upper = word_to_find;
		word_to_find_upper[0] = toupper(word_to_find[0]);
    }

	// This function goes through its subset of iterators and checks to see if they match
	// either of the pattern words.  If the pattern matches, then the sum is iterated.
    template <typename IteratorType> void map(IteratorType begin, IteratorType end)
    {
		for (auto i = begin; i != end; ++i)
		{
			// if the word matches, iterate the sum
			if (*i == word_to_find_ || *i == word_to_find_upper) sum_ += 1;
		}
    }
	
	// Add together all of the sums.
    void reduce(const word_counter& other)
    {
		sum_ += other.sum_;
    }

	// return the result intiger
    int get_count() const
    {
        return sum_;
    }
	
private:
	int sum_;						// holds the number of words matched
	std::string word_to_find_;		// holds the lower case rendition of the match word
	std::string word_to_find_upper; // holds the Capital started rendition of the Match Word.
};

#endif // __WORD_COUNTER_H