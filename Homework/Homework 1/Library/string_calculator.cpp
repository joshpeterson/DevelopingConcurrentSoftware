#include <string>
#include "string_calculator.h"

int add(const std::string& left, const std::string& right)
{
	return atoi(left.c_str()) + atoi(right.c_str());
}

int subtract(const std::string& left, const std::string& right)
{
	return atoi(left.c_str()) - atoi(right.c_str());
}

int multiply(const std::string& left, const std::string& right)
{
	return atoi(left.c_str()) * atoi(right.c_str());
}

int divide(const std::string& left, const std::string& right)
{
	int divisor = atoi(right.c_str());
	if (divisor == 0)
		throw std::domain_error("Divide by zero exception");
	return atoi(left.c_str()) / divisor;
}