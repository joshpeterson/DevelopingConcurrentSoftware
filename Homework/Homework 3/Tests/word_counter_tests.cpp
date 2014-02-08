#include "gtest/gtest.h"
#include "word_counter.h"
#include "parallel_task.h"

TEST(WordCounterTests, GetCountReturnsZeroByDefault)
{
    word_counter counter;
    ASSERT_EQ(0, counter.get_count());
}

TEST(WordCounterTests, ReduceCopiesValueReceived)
{
	word_counter counter_1;
	word_counter counter_2;

	counter_2.debug(5);

	counter_1.reduce(counter_2);
	ASSERT_EQ(5, counter_1.get_count());
}

//This test can fail for two reasons, making it a somewhat bad test, but there is no other way that we can see to do it.

TEST(WordCounterTests, ConstructorAcceptsWordAndMapCountsIt)
{
	std::vector<std::string> testString = { "hi", "hi", "hi", "hi" };
	word_counter counter("hi");
	counter.map(testString.begin(), testString.end());
	ASSERT_EQ(4, counter.get_count());
}

TEST(WordCounterTests, MapIgnoresWrongWords)
{
	std::vector<std::string> testString = { "hi","bye", "bye", "hi", "hi","HelloJoshPeterson", "hi" };
	word_counter counter("hi");
	counter.map(testString.begin(), testString.end());
	ASSERT_EQ(4, counter.get_count());
}

TEST(WordCounterTests, MapIgnoresCase)
{
	std::vector<std::string> testString = { "Hi", "hI", "hi", "HI" };
	word_counter counter("hi");
	counter.map(testString.begin(), testString.end());
	ASSERT_EQ(4, counter.get_count());
}

TEST(WordCounterTests, ParallelTaskWorksSerially)
{
	std::vector<std::string> testString = { "hi", "hi", "hi", "hi" };
	word_counter counter;

	auto task = make_parallel_task(testString.begin(), testString.end(), counter, "hi", 1);
	task.start();
	task.complete();

	ASSERT_EQ(4, counter.get_count());
}

TEST(WordCounterTests, ParallelTaskWorksInParallel)
{
	std::vector<std::string> testString = { "hi", "hi", "hi", "hi" };
	word_counter counter;

	auto task = make_parallel_task(testString.begin(), testString.end(), counter, "hi", 4);
	task.start();
	task.complete();

	ASSERT_EQ(4, counter.get_count());
}