#include "gtest/gtest.h"
#include "word_counter.h"

TEST(WordCounterTests, GetCountReturnsZeroByDefault)
{
    word_counter counter;
    ASSERT_EQ(0, counter.get_count());
}

TEST(WordCounterTests, OneArgConstructSucessLower)
{
	word_counter counter("Aoeu");
	ASSERT_EQ("aoeu", counter.get_word());
}


TEST(WordCounterTests, MapCorrectlyCounts1)
{
	word_counter counter("rain");
	std::vector<std::string> s = { "The", "rain", "in", "Spain", "falls", "mainly", "on", "the", "plain" };
	counter.map(s.begin(), s.end());
	ASSERT_EQ(1, counter.get_count());
}

TEST(WordCounterTests, CaseInsensitiveMap)
{
	word_counter counter("tHe");
	std::vector<std::string> s = { "The", "rain", "in", "Spain", "falls", "mainly", "on", "the", "plain" };
	counter.map(s.begin(), s.end());
	ASSERT_EQ(2, counter.get_count());
}