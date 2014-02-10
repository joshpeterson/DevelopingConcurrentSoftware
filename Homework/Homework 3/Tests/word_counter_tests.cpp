#include "gtest/gtest.h"
#include "word_counter.h"
#include <vector>
//#include "parallel_task.h"

TEST(WordCounterTests, GetCountReturnsZeroByDefault)
{
    word_counter counter;
    ASSERT_EQ(0, counter.get_count());
}

TEST(WordCounterTests, GetCountReturnsZeroByDefault2)
{
	word_counter counter;
	std::vector<std::string> test;
	
	auto task = make_parallel_task(test.begin(), test.end(), counter, "test", 4);
	task.start();
	task.complete();

	ASSERT_EQ(0, counter.get_count());
}

TEST(WordCounterTests, GetCountReturnsOne)
{
	word_counter counter;
	std::vector<std::string> test;
	test.push_back("test");

	auto task = make_parallel_task(test.begin(), test.end(), counter, "test", 4);
	task.start();
	task.complete();

	ASSERT_EQ(1, counter.get_count());
}

TEST(WordCounterTests, GetCountReturnsTwo)
{
	word_counter counter;
	std::vector<std::string> test;
	test.push_back("test");
	test.push_back("Test");

	auto task = make_parallel_task(test.begin(), test.end(), counter, "test", 4);
	task.start();
	task.complete();

	ASSERT_EQ(2, counter.get_count());
}