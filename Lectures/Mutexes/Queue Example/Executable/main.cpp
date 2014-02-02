#include <iostream>
#include <thread>
#include "producer_consumer_queue.h"
#include "gauss.h"

int main()
{
    producer_consumer_queue queue;

    for (int i = 1; i <= 10000; ++i)
        queue.enqueue(i);

    int sum1;
    int sum2;

    std::thread consumer1(gauss, std::ref(queue), std::ref(sum1));
    std::thread consumer2(gauss, std::ref(queue), std::ref(sum2));
    
    consumer1.join();
    consumer2.join();

    std::cout << "sum1: " << sum1 << std::endl;
    std::cout << "sum2: " << sum2 << std::endl;
    std::cout << "The sum is: " << sum1 + sum2 << std::endl;

	std::cout << "Press any key to continue...\n";
	std::getchar();
}