#include <iostream>
#include <string>
#include "thread_neutral_cache.h"
#include "thread_safe_cache.h"

int main()
{
    thread_neutral_cache<int, std::string> neutral_cache;
    thread_safe_cache<int, std::string> safe_cache;

    std::cout << "Press any key to continue...\n";
    std::getchar();
}