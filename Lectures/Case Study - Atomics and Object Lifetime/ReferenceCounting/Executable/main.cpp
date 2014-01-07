#include <iostream>
#include <thread>
#include <vector>
#include "reference_counted.h"

void releaser(reference_counted<int>* tester, int call_identifier)
{
    tester->release(call_identifier);
}

int main()
{
    reference_counted<int> tester(42);
    std::vector<std::thread> threads;

    // Increment reference count so multiple threads will have time to launch.
    for (auto i = 0; i < 1000; ++i)
        tester.add_reference();

    for (auto i = 0; i < 1000; ++i)
        threads.push_back(std::thread(&releaser, &tester, i));

    for (auto& thread : threads)
        thread.join();

    std::cout << "Press any key to continue...\n";
    std::getchar();
}