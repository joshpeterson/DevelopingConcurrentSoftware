#include "gtest/gtest.h"
#include "../Library/mpi_word_counter.h"
#include <vector>
#include <string>

TEST(WordCounterTests, GetCountReturnsZeroByDefault)
{
    mpi_word_counter counter("unused", std::vector<std::string>());
    ASSERT_EQ(0, counter.get_count());
}

TEST(WordCounterTests, MapCountsTheNumberOfOccurencesOfTheWord)
{
    std::vector<std::string> input = { "foo", "bar", "foo" };
    mpi_word_counter counter("foo", input);

    counter.map(0, 2);

    ASSERT_EQ(2, counter.get_count());
}

TEST(WordCounterTests, MapCountsTheNumberOfOccurencesOfTheWordIgnoringCase)
{
    std::vector<std::string> input = { "foo", "bar", "Foo", "Foo" };
    mpi_word_counter counter("foo", input);

    counter.map(0, 3);

    ASSERT_EQ(3, counter.get_count());
}

TEST(WordCounterTests, ReduceAddsTheCountPassedToReduce)
{
    std::vector<std::string> input = { "foo", "bar", "Foo", "Foo" };
    mpi_word_counter counter("foo", input);

    counter.map(0, 3);

    counter.reduce(4);

    ASSERT_EQ(7, counter.get_count());
}

TEST(WordCounterTests, CopyConstructorCopiesAllNecessaryPrivateMembers)
{
    std::vector<std::string> input = { "foo", "bar", "foo" };
    mpi_word_counter counter("foo", input);
    mpi_word_counter copy_of_counter(counter);

    copy_of_counter.map(0, 2);

    ASSERT_EQ(2, copy_of_counter.get_count());
}