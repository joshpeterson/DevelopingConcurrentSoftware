#include "gtest/gtest.h"
#include "../Library/mpi_word_counter.h"

TEST(MpiWordCounterTests, GetCountReturnsZeroByDefault)
{
    mpi_word_counter counter("unused", std::vector<std::string>());
    ASSERT_EQ(0, counter.get_count());
}


void map(unsigned int begin, unsigned int end);
unsigned int reduce(unsigned int input);

TEST(MpiWordCounterTests, WordIsMapped)
{
	std::vector<std::string> s = { "The", "rain", "in", "Spain", "falls", "mainly", "on", "the", "plain" };
	mpi_word_counter counter("unused", s);
	ASSERT_EQ("unused", counter.get_word());

}

TEST(MpiWordCounterTests, WordIsLowered)
{
	std::vector<std::string> s = { "The", "rain", "in", "Spain", "falls", "mainly", "on", "the", "plain" };
	mpi_word_counter counter("Spain", s);
	ASSERT_EQ("spain", counter.get_word());
}

TEST(MpiWordCounterTests, FoundLowerCaseWord)
{
	std::vector<std::string> s = { "The", "rain", "in", "Spain", "falls", "mainly", "on", "the", "plain" };
	mpi_word_counter counter("rain", s);
	counter.map(0, s.size());
	ASSERT_EQ(1, counter.get_count());
}

TEST(MpiWordCounterTests, FoundUpperCaseWord)
{
	std::vector<std::string> s = { "The", "rain", "in", "Spain", "falls", "mainly", "on", "the", "plain" };
	mpi_word_counter counter("Spain", s);
	counter.map(0, s.size());
	ASSERT_EQ(1, counter.get_count());
}

TEST(MpiWordCounterTests, FoundMixedCaseWords)
{
	std::vector<std::string> s = { "The", "rain", "in", "Spain", "falls", "mainly", "on", "the", "plain" };
	mpi_word_counter counter("The", s);
	counter.map(0, s.size());
	ASSERT_EQ(2, counter.get_count());
}