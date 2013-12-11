#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

// We want to write this, since it is simple:
// bool should_exit;
std::atomic<bool> should_exit;

void func()
{
    int counter = 0;
    while (!should_exit)
        ++counter;

    std::cout << "Counter value: " << counter << std::endl;
}

int main()
{
    should_exit = false;
    std::thread t(func);

    // Simulate doing something
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    should_exit  = true;
    t.join();

    std::cout << "Press any key to continue...\n";
    std::getchar();
}