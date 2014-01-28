#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int shared;

void reader()
{
	m.lock();
    std::cout << "The value of shared is: " << shared << std::endl;
	m.unlock();
}

void writer()
{
	m.lock();
    for (int i = 0; i < 1000000; ++i)
        shared++;
	m.unlock();
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