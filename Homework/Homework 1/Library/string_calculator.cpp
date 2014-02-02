#include <string>
#include <sstream>
#include <stdexcept>
#include "string_calculator.h"
#include <exception>


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
	int left_int; int right_int;

	// string to int
	left_int = std::stoi(left);
	right_int = std::stoi(right);

	// addition
    return left_int+right_int;
=======
    int left_value;
    int right_value;

    parse_arguments(left, right, left_value, right_value);

    return left_value + right_value;
>>>>>>> 252682de54d10a831430004e3935f3516dc08b2a
}

int subtract(const std::string& left, const std::string& right)
{
<<<<<<< HEAD
	int left_int; int right_int;

	// string to int
	left_int = std::stoi(left);
	right_int = std::stoi(right);

	// subtraction
	return (left_int - right_int);
=======
    int left_value;
    int right_value;

    parse_arguments(left, right, left_value, right_value);

    return left_value - right_value;
>>>>>>> 252682de54d10a831430004e3935f3516dc08b2a
}

int multiply(const std::string& left, const std::string& right)
{
<<<<<<< HEAD
	int left_int, right_int;

	// string to int
	left_int = std::stoi(left);
	right_int = std::stoi(right);

	// multiplication
    return (left_int*right_int);
=======
    int left_value;
    int right_value;

    parse_arguments(left, right, left_value, right_value);

    return left_value * right_value;
>>>>>>> 252682de54d10a831430004e3935f3516dc08b2a
}

int divide(const std::string& left, const std::string& right)
{
<<<<<<< HEAD
	int left_int, right_int, result;

	// String to Int
	left_int = std::stoi(left);
	right_int = std::stoi(right);

	// Exception checking
	if (right_int == 0)
	{
		throw std::invalid_argument("Divide by Zero!");
	}
	
	// Division
	return (left_int / right_int);
}
=======
    int left_value;
    int right_value;

    parse_arguments(left, right, left_value, right_value);

    if (right_value == 0)
        throw std::invalid_argument("Right argument cannot be zero.");

    return left_value / right_value;
}
>>>>>>> 252682de54d10a831430004e3935f3516dc08b2a
