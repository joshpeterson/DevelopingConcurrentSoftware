#include "gtest/gtest.h"
#include "thread_safe_vector.h"

TEST(ThreadSafeVectorTests, InitialSizeIsZero)
{
    thread_safe_vector<int> container;

    ASSERT_EQ(0, container.size());
}


TEST(ThreadSafeVectorTests, LockingWorks)
{
	thread_safe_vector<int> container;
	container.push_back(2);
	ASSERT_EQ(1, container.size());
}


