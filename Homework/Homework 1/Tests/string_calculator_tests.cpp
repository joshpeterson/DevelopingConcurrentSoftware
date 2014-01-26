#include "gtest/gtest.h"
#include "../Library/string_calculator.h"

// Addition Tests
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

TEST(StringCalculatorTests, SumOfOneAndOneIsTwo)
{
	ASSERT_EQ(2, add("1", "1"));
}

// Subtraction Tests
TEST(StringCalcultor, SubtractionOfNull)
{
	ASSERT_EQ(0, subtract("0", "0"));
}

TEST(StringCalculator, SubtractionOfOneAndZero)
{
	ASSERT_EQ(1, subtract("1", "0"));
}

TEST(StringCalculator, SubtractionOfZeroAndOne)
{
	ASSERT_EQ(-1, subtract("0", "1"));
}

// Multiplication Tests
TEST(StringCalculator, MultiplicationZeroAndZero)
{
	ASSERT_EQ(0, multiply("0", "0"));
}

TEST(StringCalculator, MultiplicationOneAndOne)
{
	ASSERT_EQ(1, multiply("1", "1"));
}

// Division Tests
TEST(StringCalculator, DivisionByOne)
{
	ASSERT_EQ(1, divide("1", "1"));
}

TEST(StringCalculator, DivisionByNegativeOne)
{
	ASSERT_EQ(-1, divide("1", "-1"));
}

TEST(StringCalculator, DivisionByZero)
{
	ASSERT_THROW(divide("1", "0"), std::invalid_argument);
}