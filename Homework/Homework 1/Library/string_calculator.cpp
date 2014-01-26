#include <string>
#include "string_calculator.h"
#include <exception>


int add(const std::string& left, const std::string& right)
{
	int left_int; int right_int;

	// string to int
	left_int = std::stoi(left);
	right_int = std::stoi(right);

	// addition
    return left_int+right_int;
}

int subtract(const std::string& left, const std::string& right)
{
	int left_int; int right_int;

	// string to int
	left_int = std::stoi(left);
	right_int = std::stoi(right);

	// subtraction
	return (left_int - right_int);
}

int multiply(const std::string& left, const std::string& right)
{
	int left_int, right_int;

	// string to int
	left_int = std::stoi(left);
	right_int = std::stoi(right);

	// multiplication
    return (left_int*right_int);
}

int divide(const std::string& left, const std::string& right)
{
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