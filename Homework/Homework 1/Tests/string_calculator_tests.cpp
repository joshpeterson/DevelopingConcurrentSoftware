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
TEST(StringCalculatorTests, SumOfOneAndOneIsTwo)
{
	ASSERT_EQ(2, add("1", "1"));
}

TEST(StringCalculatorTests, DifferenceOfZeroAndZeroIsZero)
{
	ASSERT_EQ(0, subtract("0", "0"));
}
TEST(StringCalculatorTests, DifferenceOfOneAndZeroIsOne)
{
	ASSERT_EQ(1, subtract("1", "0"));
}
TEST(StringCalculatorTests, DifferenceOfOneAndOneIsZero)
{
	ASSERT_EQ(0, subtract("1", "1"));
}
TEST(StringCalculatorTests, DifferenceOfZeroAndOneIsNegativeOne)
{
	ASSERT_EQ(-1, subtract("0", "1"));
}


TEST(StringCalculatorTests, ProductOfZeroAndZeroIsZero)
{
	ASSERT_EQ(0, multiply("0", "0"));
}
TEST(StringCalculatorTests, ProductOfOneAndZeroIsZero)
{
	ASSERT_EQ(0, multiply("1", "0"));
}
TEST(StringCalculatorTests, ProductOfOneAndOneIsOne)
{
	ASSERT_EQ(1, multiply("1", "1"));
}

TEST(StringCalculatorTests, QuotientOfZeroAndOneIsZero)
{
	ASSERT_EQ(0, divide("0", "1"));
}
TEST(StringCalculatorTests, QuotientOfOneAndOneIsOne)
{
	ASSERT_EQ(1, divide("1", "1"));
}

TEST(StringCalculatorTests, DifferenceOfOneAndZeroIsUndefined)
{
	ASSERT_ANY_THROW(divide("1", "0"));
}
