#include <stdexcept>

#include "gtest/gtest.h"
#include "sum.h"

using namespace library;

TEST(SumTests, SumsZeroAndZero)
{
<<<<<<< HEAD
<<<<<<< HEAD

}
=======
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
>>>>>>> origin/FinishedAddTwoIntegersExample
=======
    auto result = sum(0, 0);
    ASSERT_EQ(0, result);
}

TEST(SumTests, SumsOneAndZero)
{
    auto result = sum(1, 0);
    ASSERT_EQ(1, result);
}

TEST(SumTests, ThrowsExceptionIfLeftIsNegtive)
{
    bool exception_caught = false;
    try
    {
       auto result = sum(-1, 0);
    }
    catch (const std::invalid_argument&)
    {
        exception_caught = true;
    }

    ASSERT_EQ(true, exception_caught) << "Eception was not thrown.";
}
>>>>>>> upstream/master
