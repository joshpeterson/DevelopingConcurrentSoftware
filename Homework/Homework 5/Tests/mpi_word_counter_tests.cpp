#include "gtest/gtest.h"
#include "../Library/mpi_word_counter.h"

TEST(MpiWordCounterTests, GetCountReturnsZeroByDefault)
{
    mpi_word_counter counter("unused", std::vector<std::string>());
    ASSERT_EQ(0, counter.get_count());
}

TEST(MpiWordCounterTests, ReduceAddsToCount_CountReturnsRealValue)
{
	mpi_word_counter counter("unused", std::vector<std::string>());
	counter.reduce(4);
	ASSERT_EQ(4, counter.get_count());
}

TEST(WordCounterTests, MapCountsTheWord)
{
	std::vector<std::string> input = { "bla", "bleh", "bla" };
	mpi_word_counter counter("bla", input);

	counter.map(0, input.size());

	ASSERT_EQ(2, counter.get_count());
}

TEST(WordCounterTests, MapCountsIgnoresCase)
{
	std::vector<std::string> input = { "bla", "bleh", "BLA", "bLa" };
	mpi_word_counter counter("bla", input);

	counter.map(0, input.size());

	ASSERT_EQ(3, counter.get_count());
}