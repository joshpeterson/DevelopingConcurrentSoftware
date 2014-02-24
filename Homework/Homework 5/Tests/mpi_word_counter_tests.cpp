#include "gtest/gtest.h"
#include "../Library/mpi_word_counter.h"

TEST(MpiWordCounterTests, GetCountReturnsZeroByDefault)
{
    mpi_word_counter counter("unused", std::vector<std::string>());
    ASSERT_EQ(0, counter.get_count());
}

std::vector<std::string> word_list = { "first_word", "Second_word", "repeating_word", "repeating_word" };

TEST(WordCounterTests, FindLowerCaseWord)
{
	mpi_word_counter counter("first_word", word_list);
	counter.map(0, word_list.size()-1);
	
	ASSERT_EQ(1, counter.get_count());
}

TEST(WordCounterTests, FindUpperCaseWord)
{
	mpi_word_counter counter("second_word", word_list);
	counter.map(0, word_list.size()-1);
	ASSERT_EQ(1, counter.get_count());
}

TEST(WordCounterTests, FindTwoWords)
{
	mpi_word_counter counter("repeating_word", word_list);
	counter.map(0, word_list.size()-1);
	ASSERT_EQ(2, counter.get_count());
}
