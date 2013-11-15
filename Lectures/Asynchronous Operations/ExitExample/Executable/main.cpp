#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex m;
std::condition_variable exit_condition;

void func()
{
    int counter = 0;
    std::unique_lock<std::mutex> lk(m);
    while (exit_condition.wait_for(lk, std::chrono::milliseconds(10)) == std::cv_status::timeout)
        ++counter;

    std::cout << "Counter value: " << counter << std::endl;
}

int main()
{
    std::thread t(func);

    // Simulate doing something
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    exit_condition.notify_one();
    t.join();

    std::cout << "Press any key to continue...\n";
    std::getchar();
}