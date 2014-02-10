#include <iostream>
#include <future>

int gauss(int start, int end)
{
    int sum = 0;
    for (auto i = start; i <= end; ++i)
        sum += i;

    return sum;
}

int main()
{
    std::future<int> sum = std::async(gauss, 1, 10000); // execute, threaded or no, just don't mess with my stuff
	//return future

    std::cout << "Sum: " << sum.get() << std::endl; //cpp will call join [for get] (and wait) or executed inline - up to OS

    std::cout << "Press any key to continue...\n";
    std::getchar();
}