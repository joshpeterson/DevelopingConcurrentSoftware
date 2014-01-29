#include <string>
#include <sstream>
#include <stdexcept>
#include "string_calculator.h"

void parse_arguments(const std::string& left, const std::string& right, int& left_value, int& right_value)
{
    std::stringstream left_stream(left);
    left_stream >> left_value;

    std::stringstream right_stream(right);
    right_stream >> right_value;
}

int add(const std::string& left, const std::string& right)
{
    int left_value;
    int right_value;

    parse_arguments(left, right, left_value, right_value);

    return left_value + right_value;
}

int subtract(const std::string& left, const std::string& right)
{
    int left_value;
    int right_value;

    parse_arguments(left, right, left_value, right_value);

    return left_value - right_value;
}

int multiply(const std::string& left, const std::string& right)
{
    int left_value;
    int right_value;

    parse_arguments(left, right, left_value, right_value);

    return left_value * right_value;
}

int divide(const std::string& left, const std::string& right)
{
    int left_value;
    int right_value;

    parse_arguments(left, right, left_value, right_value);

    if (right_value == 0)
        throw std::invalid_argument("Right argument cannot be zero.");

    return left_value / right_value;
}
