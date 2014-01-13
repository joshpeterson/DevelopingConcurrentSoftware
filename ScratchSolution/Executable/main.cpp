#include <iostream>
#include "../Library/hello.h"

int main()
{
    std::cout << library::get_message();

    std::cout << "Press any key to continue...\n";
    std::getchar();
}