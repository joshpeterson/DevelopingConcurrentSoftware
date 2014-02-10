#include "gtest/gtest.h"
#include "word_counter.h"

TEST(WordCounterTests, GetCountReturnsZeroByDefault)
{
    word_counter counter;
    ASSERT_EQ(0, counter.get_count());
}

std::vector<std::string> word_list = { "first_word", "Second_word", "repeating_word", "repeating_word"};

TEST(WordCounterTests, FindLowerCaseWord)
{
	word_counter counter("first_word");
	counter.map(word_list.begin(), word_list.end());
	ASSERT_EQ(1, counter.get_count());
}

TEST(WordCounterTests, FindUpperCaseWord)
{
	word_counter counter("second_word");
	counter.map(word_list.begin(), word_list.end());
	ASSERT_EQ(1, counter.get_count());
}

TEST(WordCounterTests, FindTwoWords)
{
	word_counter counter("repeating_word");
	counter.map(word_list.begin(), word_list.end());
	ASSERT_EQ(2, counter.get_count());
}
