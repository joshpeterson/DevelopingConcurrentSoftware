#include "gtest/gtest.h"
#include "word_counter.h"

TEST(WordCounterTests, GetCountReturnsZeroByDefault)
{
    word_counter counter;
    ASSERT_EQ(0, counter.get_count());
}

//checks that the first element is counted specifically
TEST(WordCounterTests, GetCountEdgeCase_Begin)
{
	std::vector<std::string> example = { "hello", "world", "world2", "world3" };
	word_counter counter("hello");
	counter.map(example.begin(), example.end());
	ASSERT_EQ(1, counter.get_count());
}


//checks that the last element is counted specifically
TEST(WordCounterTests, GetCountEdgeCase_End)
{
	std::vector<std::string> example = { "hello", "hello2", "hello3", "world" };
	word_counter counter("world");
	counter.map(example.begin(), example.end());
	ASSERT_EQ(1, counter.get_count());
}


//checks that the equality checks are ignoring case
TEST(WordCounterTests, GetCaseInsensitiveSimpleCount)
{
	std::vector<std::string> example = { "hElLo", "HellO", "HELLO", "HEllO" };
	word_counter counter("heLLO");
	counter.map(example.begin(), example.end());
	ASSERT_EQ(4, counter.get_count());
}

//checks that the reduce function is correctly adding the results of two tasks
TEST(WordCounterTests, CheckReduceIsSummingCorrectly)
{
	//four fours and three threes
	std::vector<std::string> example = { "four", "four", "three", "four","three","three","four"};
	word_counter counter1("four");
	word_counter counter2("three");
	counter1.map(example.begin(), example.end());
	counter2.map(example.begin(), example.end());

	ASSERT_EQ(4, counter1.get_count());
	ASSERT_EQ(3, counter2.get_count());

	counter1.reduce(counter2);
	ASSERT_EQ(7, counter1.get_count()); //4+3
}