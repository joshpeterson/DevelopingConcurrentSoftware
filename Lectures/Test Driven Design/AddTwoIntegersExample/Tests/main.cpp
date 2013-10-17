#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char** argv) 
{ 
    testing::InitGoogleTest(&argc, argv); 
    RUN_ALL_TESTS();

	std::cout << "Press any key to continue...\n";
	std::getchar();
}