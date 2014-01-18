#include <stdexcept>

#include "gtest/gtest.h"
#include "sum.h"

using namespace library;

TEST(SumTests, SumsZeroAndZero)
{
    auto result = sum(0,0);
    ASSERT_EQ(0, result);
}

TEST(SumTests, SumsOneAndOne)
{
    auto result = sum(1,1);
    ASSERT_EQ(2, result);
}

TEST(SumTests, ThrowsAnExceptionWithNegativeLeftInput)
{
    ASSERT_THROW(sum(-2, 3), std::invalid_argument);
}

TEST(SumTests, ThrowsAnExceptionWithNegativeRightInput)
{
    ASSERT_THROW(sum(2, -33), std::invalid_argument);
}

TEST(SumTests, ExceptionHasExpectedMessageForNegativeLeftInput)
{
    try
    {
        sum(-2, 4);
    }
    catch (const std::invalid_argument& e)
    {
        ASSERT_STREQ("The left input cannot be negative.", e.what());
    }
}

TEST(SumTests, ExceptionHasExpectedMessageForNegativeRightInput)
{
    try
    {
        sum(2, -4);
    }
    catch (const std::invalid_argument& e)
    {
        ASSERT_STREQ("The right input cannot be negative.", e.what());
    }
}
