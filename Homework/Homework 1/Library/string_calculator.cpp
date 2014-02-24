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
<<<<<<< HEAD
	return atoi(left.c_str()) + atoi(right.c_str());
=======
    int left_value;
    int right_value;

    parse_arguments(left, right, left_value, right_value);

    return left_value + right_value;
>>>>>>> 062c77192f80d862961d77ca50bbebf97c987e57
}

int subtract(const std::string& left, const std::string& right)
{
<<<<<<< HEAD
	return atoi(left.c_str()) - atoi(right.c_str());
=======
    int left_value;
    int right_value;

    parse_arguments(left, right, left_value, right_value);

    return left_value - right_value;
>>>>>>> 062c77192f80d862961d77ca50bbebf97c987e57
}

int multiply(const std::string& left, const std::string& right)
{
<<<<<<< HEAD
	return atoi(left.c_str()) * atoi(right.c_str());
=======
    int left_value;
    int right_value;

    parse_arguments(left, right, left_value, right_value);

    return left_value * right_value;
>>>>>>> 062c77192f80d862961d77ca50bbebf97c987e57
}

int divide(const std::string& left, const std::string& right)
{
<<<<<<< HEAD
	int divisor = atoi(right.c_str());
	if (divisor == 0)
		throw std::domain_error("Divide by zero exception");
	return atoi(left.c_str()) / divisor;
}
=======
    int left_value;
    int right_value;

    parse_arguments(left, right, left_value, right_value);

    if (right_value == 0)
        throw std::invalid_argument("Right argument cannot be zero.");

    return left_value / right_value;
}
>>>>>>> 062c77192f80d862961d77ca50bbebf97c987e57
