#include "gtest/gtest.h"
#include "../Library/string_calculator.h"

TEST(StringCalculatorTests, SumOfZeroAndZeroIsZero)
{
	ASSERT_EQ(0, add("0", "0"));
}

// the way ReadLeftProperly and ReadRightProperly and the code
// implementing them were originally written, one of them would always
// fail. However, I modified both the test and the code so that both
// tests would pass and the code would be right.

TEST(StringCalculatorTests, ReadLeftProperly)
{
	ASSERT_EQ(1, add("1", "0"));
}

TEST(StringCalculatorTests, ReadRightProperly)
{
	ASSERT_EQ(1, add("0", "1"));
}

TEST(StringCalculatorTests, SumCorrectly)
{
	ASSERT_EQ(2, add("1", "1"));
	ASSERT_EQ(20, add("15", "5"));
}

// SUBTRACTION TESTS:

TEST(StringCalculatorTests, ZeroMinusZeroIsZero)
{
	ASSERT_EQ(0, subtract("0", "0"));
}

TEST(StringCalculatorTests, OneMinusZeroIsOne)
{
	ASSERT_EQ(1, subtract("1", "0"));
}

TEST(StringCalculatorTest, OneMinusOneIsZero)
{
	ASSERT_EQ(0, subtract("1", "1"));
}

TEST(StringCalculatorTest, FourMinusFiveIsNeg)
{
	ASSERT_EQ(-1, subtract("4", "5"));
}


// MULTIPLY

TEST(StringCalculatorTest, OneTimesOneIsOne)
{
	ASSERT_EQ(1, multiply("1", "1"));
}

TEST(StringCalculatorTest, TwoTimesOneIsTwo)
{
	ASSERT_EQ(2, multiply("2", "1"));
}

TEST(StringCalculatorTest, TwoTimesThreeIsSix)
{
	ASSERT_EQ(6, multiply("2", "3"));
}

// DIVIDE

TEST(StringCalculatorTest, OneDividedByOneIsOne)
{
	ASSERT_EQ(1, divide("1", "1"));
}

TEST(StringCalculatorTest, TwoDividedByOneIsTwo)
{
	ASSERT_EQ(2, divide("2", "1"));
}

TEST(StringCalculatorTest, FourDividedByTwoIsTwo)
{
	ASSERT_EQ(2, divide("4", "2"));
}

TEST(StringCalculatorTest, DivideByZero)
{
	ASSERT_ANY_THROW(divide("5", "0"));
}

