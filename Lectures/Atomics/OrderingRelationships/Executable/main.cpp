#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::vector<int> data;
std::atomic<bool> data_ready = false;

void reader_thread()
{
    int i = 1;
    while (!data_ready) // 1
    {
        std::cout << "Reader loop " << i << std::endl;
        ++i;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    std::cout << "Data value: " << data[0] << std::endl; // 2
}

void writer_thread()
{
    // Pretend to do some work
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    data.push_back(42); // 3
    data_ready = true;  // 4
}

int main()
{
    std::thread reader(reader_thread);
    std::thread writer(writer_thread);

    writer.join();
    reader.join();

    std::cout << "Press any key to continue...\n";
    std::getchar();
}