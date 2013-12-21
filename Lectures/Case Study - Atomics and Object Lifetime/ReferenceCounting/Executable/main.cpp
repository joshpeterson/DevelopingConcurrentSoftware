#include <iostream>
#include <thread>
#include <chrono>
#include "reference_counted.h"

void releaser(reference_counted* tester, int call_identifier)
{
	tester->release(call_identifier);
}

int main()
{
	reference_counted tester;

	// Increment reference count so multiple threads will have time to launch.
	for (auto i = 0; i < 4500; ++i)
		tester.add_reference();

	for (auto i = 0; i < 10000; ++i)
		std::thread(&releaser, &tester, i).detach();

	std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "Press any key to continue...\n";
    std::getchar();
}