#include <iostream>
#include <string>
#include <sstream>
#include "thread_neutral_cache.h"
#include "thread_safe_cache.h"

std::string convert_value(int value)
{
    std::cout << "The convert_value method was called with value = " << value << std::endl;

    std::stringstream message;
    message << "The value is " << value;
    return message.str();
}

int main()
{
    thread_neutral_cache<int, std::string> neutral_cache;
    thread_safe_cache<int, std::string> safe_cache;

    auto value_with_42 = neutral_cache.get(42, [] { return convert_value(42); });
    auto value_with_43 = neutral_cache.get(43, [] { return convert_value(43); });
    auto value_with_44 = neutral_cache.get(44, [] { return convert_value(44); });
    auto value_two_with_42 = neutral_cache.get(42, [] { return convert_value(42); });

    std::cout << "Press any key to continue...\n";
    std::getchar();
}