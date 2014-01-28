#include <string>
#include "string_calculator.h"

int add(const std::string& left, const std::string& right)
{
	return (atoi(left.c_str()) + atoi(right.c_str()));
}

int subtract(const std::string& left, const std::string& right)
{
	return (atoi(left.c_str()) - atoi(right.c_str()));
}

int multiply(const std::string& left, const std::string& right)
{
	return (atoi(left.c_str()) * atoi(right.c_str()));
}

int divide(const std::string& left, const std::string& right)
{
	if (atoi(right.c_str()) == 0)
		throw 20;
	return (atoi(left.c_str()) / atoi(right.c_str()));
}