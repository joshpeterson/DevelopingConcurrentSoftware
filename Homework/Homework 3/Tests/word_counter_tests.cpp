#include "gtest/gtest.h"
#include "word_counter.h"
#include <vector>
#include <string>

TEST(WordCounterTests, GetCountReturnsZeroByDefault)
{
    word_counter counter;
    ASSERT_EQ(0, counter.get_count());
}

TEST(WordCounterTests, MapCountsTheNumberOfOccurencesOfTheWord)
{
    word_counter counter("foo");
    std::vector<std::string> input = { "foo", "bar", "foo" };

    counter.map(input.begin(), input.end());

    ASSERT_EQ(2, counter.get_count());
}

TEST(WordCounterTests, MapCountsTheNumberOfOccurencesOfTheWordIgnoringCase)
{
    word_counter counter("foo");
    std::vector<std::string> input = { "foo", "bar", "Foo", "Foo" };

    counter.map(input.begin(), input.end());

    ASSERT_EQ(3, counter.get_count());
}

TEST(WordCounterTests, ReduceAddsTheCountFromTheOtherTask)
{
    word_counter other_counter("foo");
    std::vector<std::string> input = { "foo", "bar", "Foo", "Foo" };

    other_counter.map(input.begin(), input.end());

    word_counter counter;
    counter.reduce(other_counter);

    ASSERT_EQ(3, counter.get_count());
}