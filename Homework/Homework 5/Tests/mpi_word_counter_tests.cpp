#include "gtest/gtest.h"
#include "../Library/mpi_word_counter.h"
#include <vector>
#include <string>


TEST(MpiWordCounterTests, GetCountReturnsZeroByDefault)
{
	mpi_word_counter counter("unused", std::vector<std::string>());
	ASSERT_EQ(0, counter.get_count());
}

//checks that the first element is counted specifically
TEST(MpiWordCounterTests, GetCountEdgeCase_Begin)
{
		std::vector<std::string> example = { "hello", "world", "world2", "world3" };
		mpi_word_counter counter("hello", example);
		counter.map(0, example.size()-1);
		ASSERT_EQ(1, counter.get_count());
}


//checks that the last element is counted specifically
TEST(MpiWordCounterTests, GetCountEdgeCase_End)
{
	std::vector<std::string> example = { "hello", "hello2", "hello3", "world" };
	mpi_word_counter counter("world", example);
	counter.map(0, example.size()-1);
	ASSERT_EQ(1, counter.get_count());
}


//checks that the equality checks are ignoring case
TEST(MpiWordCounterTests, GetCaseInsensitiveSimpleCount)
{
	std::vector<std::string> example = { "hElLo", "HellO", "HELLO", "HEllO" };
	mpi_word_counter counter("heLLO", example);
	counter.map(0, example.size()-1);
	ASSERT_EQ(4, counter.get_count());
}

//checks that the reduce function is correctly adding the results of two tasks
TEST(MpiWordCounterTests, CheckReduceIsSummingCorrectly)
{
	//four fours and three threes
	std::vector<std::string> example = { "four", "four", "three", "four", "three", "three", "four" };
	mpi_word_counter counter1("four", example);
	mpi_word_counter counter2("three", example);
	counter1.map(0, example.size()-1);
	counter2.map(0, example.size()-1);

	counter1.reduce(counter2.get_count());
	ASSERT_EQ(7, counter1.get_count()); //4+3
}