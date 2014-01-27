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

TEST(StringCalculatorTests, NegativeAddition)
{
	ASSERT_EQ(0, add("-1", "1"));
}

TEST(StringCalculatorTests, MultipleDigitAddition)
{
	ASSERT_EQ(12, add("10", "2"));
}

TEST(StringCalculatorTests, DifferenceOfZeroAndZeroIsZero)
{
	ASSERT_EQ(0, subtract("0", "0"));
}

TEST(StringCalculatorTests, DifferenceOfOneAndZeroIsOne)
{
	ASSERT_EQ(1, subtract("1", "0"));
}

TEST(StringCalculatorTests, DifferenceOfZeroAndOneIsNegativeOne)
{
	ASSERT_EQ(-1, subtract("0", "1"));
}

TEST(StringCalculatorTests, NegativeSubtraction)
{
	ASSERT_EQ(-2, subtract("-1", "1"));
}

TEST(StringCalculatorTests, MultipleDigitSubtraction)
{
	ASSERT_EQ(10, subtract("12", "2"));
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

TEST(StringCalculatorTests, ProductOfNegativeOneAndOneIsNegativeOne)
{
	ASSERT_EQ(-1, multiply("-1", "1"));
}

TEST(StringCalculatorTests, ProductOfNegativeOneAndNegativeOneIsOne)
{
	ASSERT_EQ(1, multiply("-1", "-1"));
}
TEST(StringCalculatorTests, QuotientOfZeroAndOneIsZero)
{
	ASSERT_EQ(0, divide("0", "1"));
}

TEST(StringCalculatorTests, QuotientOfOneAndZeroIsUndefined)
{
	ASSERT_ANY_THROW(divide("1", "0"));
}

TEST(StringCalculatorTests, QuotientOfOneAndOneIsOne)
{
	ASSERT_EQ(1, divide("1", "1"));
}