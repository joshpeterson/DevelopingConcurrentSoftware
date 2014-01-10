#include "gtest/gtest.h"
#include "../Library/string_calculator.h"

TEST(StringCaclulatorTests, SumOfZeroAndZeroIsZero)
{
    ASSERT_EQ(0, add("0", "0"));
}