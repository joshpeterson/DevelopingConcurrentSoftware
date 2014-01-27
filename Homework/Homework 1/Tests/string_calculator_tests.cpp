#include "gtest/gtest.h"
#include "../Library/string_calculator.h"

TEST(StringCalculatorTests, SumOfZeroAndZeroIsZero)
{
    ASSERT_EQ(0, add("0", "0"));
}

TEST(StringCalculatorTests, SumOfZeroAnd7Is7)
{
	ASSERT_EQ(7, add("0", "7"));
}

TEST(StringCalculatorTests, SumOf4And7Is11)
{
	ASSERT_EQ(11, add("4", "7"));
}

TEST(StringCalculatorTests, SumOfnegative4and7is3)
{
	ASSERT_EQ(3, add("-4", "7"));
}

TEST(StringCalculatorTests, DifferenceOfZeroAndZeroIsZero)
{
	ASSERT_EQ(0, subtract("0", "0"));
}

TEST(StringCalculatorTests, DifferenceOf7AndZeroIs7)
{
	ASSERT_EQ(7, subtract("7", "0"));
}

TEST(StringCalculatorTests, DifferenceOf7And4Is3)
{
	ASSERT_EQ(3, subtract("7", "4"));
}

TEST(StringCalculatorTests, ProductOfZeroAndZeroIs0)
{
	ASSERT_EQ(0, multiply("0", "0"));
}

TEST(StringCalculatorTests, ProductOfZeroAnd7Is0)
{
	ASSERT_EQ(0, multiply("0", "7"));
}

TEST(StringCalculatorTests, ProductOf4And7Is28)
{
	ASSERT_EQ(28, multiply("4", "7"));
}

TEST(StringCalculatorTests, ProductOfNegative4And7IsNeg28)
{
	ASSERT_EQ(-28, multiply("-4", "7"));
}

TEST(StringCalculatorTests, DivisionOfOneAndOneIs1)
{
	ASSERT_EQ(1, divide("1", "1"));
}

TEST(StringCalculatorTests, DivisionOf10And5Is2)
{
	ASSERT_EQ(2, divide("10", "5"));
}

TEST(StringCalculatorTests, DivisionOfNeg10and5IsNeg2)
{
	ASSERT_EQ(-2, divide("-10", "5"));
}

TEST(StringCalculatorTests, DivisionOf7ByZeroIsThrow)
{
	ASSERT_ANY_THROW(divide("7", "0"));
}


