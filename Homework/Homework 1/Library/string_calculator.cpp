#include <string>
#include "string_calculator.h"

int add(const std::string& left, const std::string& right)
{
	int leftInt;
	int rightInt;
	leftInt = atoi(left.c_str());
	rightInt = atoi(right.c_str());
    return leftInt+rightInt;
}

int subtract(const std::string& left, const std::string& right)
{
	int leftInt;
	int rightInt;
	leftInt = atoi(left.c_str());
	rightInt = atoi(right.c_str());
	return leftInt-rightInt;
}

int multiply(const std::string& left, const std::string& right)
{
	int leftInt;
	int rightInt;
	leftInt = atoi(left.c_str());
	rightInt = atoi(right.c_str());
	return leftInt*rightInt;
}

int divide(const std::string& left, const std::string& right)
{
	int leftInt;
	int rightInt;
	leftInt = atoi(left.c_str());
	rightInt = atoi(right.c_str());
	if (rightInt != 0)
		return leftInt / rightInt;
	else
		throw(std::invalid_argument("Divide by 0 error"));
}