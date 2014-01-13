#include <iostream>
#include <string>
#include <functional>
#include <stdexcept>
#include "string_calculator.h"

void validate(std::string, std::string, int, std::function<int(std::string, std::string)>, std::string);
template<typename ExceptionType>
void validate_exception(std::string, std::string, int, std::function<int(std::string, std::string)>, std::string, std::string);

int main()
{
    validate("1", "6", 7, add, "+");
    validate("-2", "13", 11, add, "+");
    validate("6", "3", 3, subtract, "-");
    validate("38", "-4", 42, subtract, "-");
    validate("12", "5", 60, multiply, "*");
    validate("-3", "6", -18, multiply, "*");
    validate("4", "2", 2, divide, "/");
    validate("13", "3", 4, divide, "/");
    validate_exception<std::invalid_argument>("10", "0", 4, divide, "/", "invalid_argument");

    std::cout << "Press any key to continue...\n";
    std::getchar();

    return 0;
}

void validate(std::string left, std::string right, int expected_result, std::function<int(std::string, std::string)> function_to_validate, std::string op)
{
    auto actual_result = function_to_validate(left, right);
    if (actual_result == expected_result)
        std::cout << left << op << right << " correct\n";
    else
        std::cout << left << op << right << " incorrect - expected: " << expected_result << " actual: " << actual_result << std::endl;
}

template<typename ExceptionType>
void validate_exception(std::string left, std::string right, int expected_result, std::function<int(std::string, std::string)> function_to_validate, std::string op, std::string exception_type)
{
    try
    {
        function_to_validate(left, right);
    }
    catch (const ExceptionType&)
    {
        std::cout << left << op << right << " correct - exception caught\n";
        return;
    }

    std::cout << left << op << right << " incorrect - expected an exception of type: " << exception_type << std::endl;
}


