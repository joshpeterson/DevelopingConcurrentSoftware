#include <string>
#include "string_calculator.h"

int add(const std::string& left, const std::string& right)
{
	int r = atoi(right.c_str());
	int l = atoi(left.c_str());
	return r+l;
}

int subtract(const std::string& left, const std::string& right)
{
	int l = atoi(left.c_str());
	int r = atoi(right.c_str());
	return l-r;
}

int multiply(const std::string& left, const std::string& right)
{
	int l = atoi(left.c_str());
	int r = atoi(right.c_str());
	return l*r;
}

int divide(const std::string& left, const std::string& right)
{
	int l = atoi(left.c_str());
	int r = atoi(right.c_str());
	if (r == 0)
		throw r;
	return l / r;	
}
