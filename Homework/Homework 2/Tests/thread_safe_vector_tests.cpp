#include "gtest/gtest.h"
#include "thread_safe_vector.h"
#include "mock_mutex.h"

TEST(ThreadSafeVectorTests, InitialSizeIsZero)
{
    thread_safe_vector<int, mock_mutex> container;

    ASSERT_EQ(0, container.size());
}

TEST(ThreadSafeVectorTests, SizeAfterPushIsOne)
{
	thread_safe_vector<int, mock_mutex> container;
	container.push_back(13);
	ASSERT_EQ(1, container.size());
}

TEST(ThreadSafeVectorTests, ValueAfterPush_13_Is13)
{
	thread_safe_vector<int, mock_mutex> container;
	container.push_back(13);
	ASSERT_EQ(13, container.at(0));
}
