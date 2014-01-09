#include "gtest/gtest.h"
#include "../Library/gauss_task.h"

TEST(GaussTaskTests, SumOfTwoValuesBetweenBeginAndEndNotIncludingEndAreReturnedByReduceInFirstVectorElement)
{
    gauss_task task;
    task.map(41, 42);

    ASSERT_EQ(41 + 42, task.get_sum());
}

TEST(GaussTaskTests, SumOfThreeValuesBetweenBeginAndEndNotIncludingEndAreReturnedByReduceInFirstVectorElement)
{
    gauss_task task;
    task.map(41, 43);

    ASSERT_EQ(41 + 42 + 43, task.get_sum());
}

TEST(GaussTaskTests, ReduceAddsEachInputToItsSum)
{
    gauss_task task;
    task.reduce(15);
    task.reduce(73);

    ASSERT_EQ(15 + 73, task.get_sum());
}