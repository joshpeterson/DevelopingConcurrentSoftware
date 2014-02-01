#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int shared;

void reader()
{
	std::lock_guard<std::mutex>lock(m);
//	m.lock();
    std::cout << "The value of shared is: " << shared << std::endl;
//	m.unlock();
}

void writer()
{
	std::lock_guard<std::mutex>lock(m);
//	m.lock();
	for (int i = 0; i < 1000000; ++i)
	{
//		std::lock_guard<std::mutex>lock(m);			// bad idea "benign" race condition
		shared++;
	}
//	m.unlock();
}

int main()
{
    shared = 3;

    std::thread writer_thread(writer);
    std::thread reader_thread(reader);

    writer_thread.detach();
    reader_thread.detach();

    std::cout << "Press any key to continue...\n";
    std::getchar();
}