#include "gtest/gtest.h"
#include "../Library/gauss_task.h"

TEST(GaussTaskTests, SumOfTwoValuesBetweenBeginAndEndNotIncludingEndAreReturnedByReduceInFirstVectorElement)
{
    gauss_task task;
    task.map(41, 43);
    auto result = task.reduce(std::vector<unsigned int>());

    ASSERT_EQ(41 + 42, result[0]);
}

TEST(GaussTaskTests, SumOfThreeValuesBetweenBeginAndEndNotIncludingEndAreReturnedByReduceInFirstVectorElement)
{
    gauss_task task;
    task.map(41, 44);
    auto result = task.reduce(std::vector<unsigned int>());

    ASSERT_EQ(41 + 42 + 43, result[0]);
}