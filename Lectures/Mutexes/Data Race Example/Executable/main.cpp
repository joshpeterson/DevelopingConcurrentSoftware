#include <iostream>
#include <thread>

int shared;

void reader()
{
    std::cout << "The value of shared is: " << shared << std::endl;
}

void writer()
{
    for (int i = 0; i < 1000000; ++i)
        shared++;
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