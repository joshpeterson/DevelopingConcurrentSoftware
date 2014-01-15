#include "gtest/gtest.h"
#include "thread_safe_vector.h"

TEST(ThreadSafeVectorTests, InitialSizeIsZero)
{
    thread_safe_vector<int> container;

    ASSERT_EQ(0, container.size());
}