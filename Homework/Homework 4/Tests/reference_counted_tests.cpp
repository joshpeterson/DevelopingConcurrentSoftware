#include "gtest/gtest.h"
#include <thread>
#include "reference_counted.h"

void releaser(reference_counted<int>* tester)
{
	tester->release();
}

TEST(RefCounterTests, _CountIsZeroByDefault)
{
	reference_counted<int> testVar(3);
	ASSERT_EQ(0, testVar._get_count());
}

TEST(RefCounterTests, valueStoresValueGiven)
{
	reference_counted<int> testVar(3);
	ASSERT_EQ(3, testVar._get_value());
}


TEST(RefCounterTests, add_referenceIncrements_Count)
{
	reference_counted<int> testVar(3);
	testVar.add_reference();
	ASSERT_EQ(1, testVar._get_count());
}

TEST(RefCounterTests, ReleaseTest)
{
	reference_counted<int> testVar(3);
	testVar.add_reference();
	testVar.add_reference();
	testVar.release();
	testVar.release();
	ASSERT_EQ(0, testVar._get_count());
}

TEST(RefCounterTests, ThreadSafety)
{
	reference_counted<int> tester(42);
	std::vector<std::thread> threads;

	// Increment reference count so multiple threads will have time to launch.
	for (auto i = 0; i < 1000; ++i)
		tester.add_reference();

	for (auto i = 0; i < 1000; ++i)
		threads.push_back(std::thread(&releaser, &tester));

	for (auto& thread : threads)
		thread.join();

}