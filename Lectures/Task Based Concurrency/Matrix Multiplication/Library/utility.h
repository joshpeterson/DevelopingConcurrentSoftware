#ifndef __UTILITY_H
#define __UTILITY_H

#include <cstdint>
#include <cstdlib>

#ifdef DEBUG_OUTPUT
#include <iostream>
#endif

namespace osoasso
{

union double_bytes
{
    double double_value;
    int64_t int_value;
};

// Implementation from http://www.cygnus-software.com/papers/comparingfloats/comparingfloats.htm
inline bool double_equal(double lhs, double rhs)
{
    double_bytes converter;
    converter.double_value = lhs;
    int64_t lhs_int = converter.int_value;

#ifdef DEBUG_OUTPUT
    std::cout << "lhs double: " << lhs << std::endl;
    std::cout << "lhs int 1: " << lhs_int << std::endl;
    std::cout << "offset:    " << (int64_t)0x8000000000000000LL << std::endl;
#endif

    // Make lhs_int lexicographically ordered as a twos-complement int
    if (lhs_int < 0)
        lhs_int = 0x8000000000000000LL - lhs_int;

#ifdef DEBUG_OUTPUT
    std::cout << "lhs int 2: " << lhs_int << std::endl;
#endif 

    // Make rhs_int lexicographically ordered as a twos-complement int
    converter.double_value = rhs;
    int64_t rhs_int = converter.int_value;

#ifdef DEBUG_OUTPUT
    std::cout << "rhs double: " << rhs << std::endl;
    std::cout << "rhs int 1: " << rhs_int << std::endl;
    std::cout << "offset:    " << (int64_t)0x8000000000000000LL << std::endl;
#endif

    if (rhs_int < 0)
        rhs_int = 0x8000000000000000LL - rhs_int;

#ifdef DEBUG_OUTPUT
    std::cout << "lhs int 2: " << rhs_int << std::endl;
#endif

    int64_t int_diff = lhs_int - rhs_int;

#ifdef DEBUG_OUTPUT
    std::cout << "int diff: " << int_diff << std::endl;
#endif

    // Use maxUlps of 4 based on comments from Google Test implementation:
    // http://code.google.com/p/googletest/source/browse/trunk/include/gtest/internal/gtest-internal.h
    if (int_diff <= 4 && int_diff >= -4)
    {
        return true;
    }

    return false;
}

}

#endif // __UTILITY_H
