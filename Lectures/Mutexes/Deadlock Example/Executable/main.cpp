#include <iostream>
#include <mutex>
#include <thread>

std::mutex mutex1;
std::mutex mutex2;

void thread1()//LOCKS MUTEX 1	
{
    std::lock_guard<std::mutex> lock1(mutex1);

    // Simulate some non-trivial execution.
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
    std::lock_guard<std::mutex> lock2(mutex2);

    std::cout << "thread 1\n";
}

void thread2()
{
    std::lock_guard<std::mutex> lock2(mutex2);
    std::lock_guard<std::mutex> lock1(mutex1);

    std::cout << "thread 2\n";
}


int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.detach();
    t2.detach();

    std::cout << "Press any key to continue...\n";
    std::getchar();
}