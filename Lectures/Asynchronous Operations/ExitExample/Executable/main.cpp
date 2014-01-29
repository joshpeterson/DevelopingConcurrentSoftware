#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#include "pi_calculator.h"

std::mutex m;
std::condition_variable exit_condition;
bool should_exit;

void func()
{
    int counter = 0;
    std::unique_lock<std::mutex> lk(m);
    while (!exit_condition.wait_for(lk, std::chrono::milliseconds(0), []{return should_exit;}))
    {
        if (should_exit)
            break;
        ++counter;
    }

    std::cout << "Counter value: " << counter << std::endl;
}

int main()
{
    should_exit = false;
    std::thread t(func);

    // Simulate doing something
    calculate_pi pi_calculator;
    pi_calculator(100000);

    should_exit  = true;
    exit_condition.notify_one();
    t.join();

    std::cout << "Press any key to continue...\n";
    std::getchar();
}