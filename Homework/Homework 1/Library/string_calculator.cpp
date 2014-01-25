#include <string>
#include <exception>
#include "string_calculator.h"

int add(const std::string& left, const std::string& right)
{
	int a = stoi(left);
	int b = stoi(right);
	return a + b;
}

int subtract(const std::string& left, const std::string& right)
{
	int a = stoi(left);
	int b = stoi(right);
	return a - b;
}

int multiply(const std::string& left, const std::string& right)
{
	int a = stoi(left);
	int b = stoi(right);
	return a*b;
}

int divide(const std::string& left, const std::string& right)
{
	int a = stoi(left);
	int b = stoi(right);

	if (b == 0) throw(std::invalid_argument("Divide By Zero!"));

	return a / b;
}

