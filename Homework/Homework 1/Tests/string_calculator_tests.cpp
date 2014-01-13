#include <stdexcept>
#include "gtest/gtest.h"
#include "../Library/string_calculator.h"

TEST(StringCalculatorTests, SumOfZeroAndZeroIsZero)
{
    ASSERT_EQ(0, add("0", "0"));
}

TEST(StringCalculatorTests, SumOfOneAndZeroIsOne)
{
    ASSERT_EQ(1, add("1", "0"));
}

TEST(StringCalculatorTests, SumOfZeroAndOneIsOne)
{
    ASSERT_EQ(1, add("0", "1"));
}

TEST(StringCalculatorTests, SumOfZeroAndNegativeOneIsNegativeOne)
{
    ASSERT_EQ(-1, add("0", "-1"));
}

TEST(StringCalculatorTests, DifferenceOfThreeAndTwoIsOne)
{
    ASSERT_EQ(1, subtract("3", "2"));
}

TEST(StringCalculatorTests, DifferenceOfTwoAndThreeIsNegativeOne)
{
    ASSERT_EQ(-1, subtract("2", "3"));
}

TEST(StringCalculatorTests, ProductOfTwoAndThreeIsSix)
{
    ASSERT_EQ(6, multiply("2", "3"));
}

TEST(StringCalculatorTests, QuotientOfSixAndThreeIsTwo)
{
    ASSERT_EQ(2, divide("6", "3"));
}

TEST(StringCalculatorTests, DivideThrowsInvalidArgumentExceptionWhenRightIsZero)
{
    ASSERT_THROW(divide("6", "0"), std::invalid_argument);
}