#include "gtest/gtest.h"
#include "sum.h"

using namespace library;

TEST(SumTests, SumsZeroAndZero)
{
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