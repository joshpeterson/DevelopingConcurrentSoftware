#include "gtest/gtest.h"
#include "../Library/mpi_word_counter.h"

TEST(MpiWordCounterTests, GetCountReturnsZeroByDefault)
{
    mpi_word_counter counter("unused", std::vector<std::string>());
    ASSERT_EQ(0, counter.get_count());
}

TEST(MpiWordCounterTests, GetCountReturnsOneForUsed)
{
	std::vector<std::string> test;
	test.push_back("used");
	mpi_word_counter counter("used", test);
	ASSERT_EQ(1, counter.get_count());
}

TEST(MpiWordCounterTests, GetCountReturnsOneForUsedUpper)
{
	std::vector<std::string> test;
	test.push_back("Used");
	mpi_word_counter counter("used", test);
	ASSERT_EQ(1, counter.get_count());
}