#include "gtest/gtest.h"
#include "pi_calculator.h"

TEST(PiCalculatorTests, PiValueAtOneIteration)
{
    ASSERT_DOUBLE_EQ(4.0, calculate_pi(1));
}

TEST(PiCalculatorTests, PiValueAtTwoIterations)
{
    ASSERT_DOUBLE_EQ(4.0 - 4.0/3.0, calculate_pi(2));
}

TEST(PiCalculatorTests, PiValueAtThreeIterations)
{
    ASSERT_DOUBLE_EQ(4.0 - 4.0/3.0 + 4.0/5.0, calculate_pi(3));
}

TEST(PiCalculatorTests, PiValueAtFourIterations)
{
    ASSERT_DOUBLE_EQ(4.0 - 4.0/3.0 + 4.0/5.0 - 4.0/7.0, calculate_pi(4));
}