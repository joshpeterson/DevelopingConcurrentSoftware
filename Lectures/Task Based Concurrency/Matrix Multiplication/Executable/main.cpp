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
	std::future<int> sum = std::async(gauss, 1, 10000);

	std::cout << "Sum:" << sum.get() << std::endl;

    std::cout << "Press any key to continue...\n";
    std::getchar();
}