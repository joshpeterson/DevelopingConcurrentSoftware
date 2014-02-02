#include <stdexcept>
#include "gtest/gtest.h"
#include "../Library/string_calculator.h"

// Addition Tests
TEST(StringCalculatorTests, SumOfZeroAndZeroIsZero)
{
    ASSERT_EQ(0, add("0", "0"));
}

TEST(StringCalculatorTests, SumOfOneAndZeroIsOne)
{
<<<<<<< HEAD
	ASSERT_EQ(1, add("1", "0"));
=======
    ASSERT_EQ(1, add("1", "0"));
>>>>>>> 252682de54d10a831430004e3935f3516dc08b2a
}

TEST(StringCalculatorTests, SumOfZeroAndOneIsOne)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 252682de54d10a831430004e3935f3516dc08b2a
}