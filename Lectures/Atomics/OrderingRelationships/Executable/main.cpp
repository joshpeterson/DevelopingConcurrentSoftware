#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::vector<int> data;
bool data_ready = false;
std::atomic<bool> data_ready = false; //added!

void reader_thread()
{
    int i = 1;
    while (!data_ready) // 1 //happens before 2
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
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); //sleep should never be done in real code - usually covering up sychronization problem (ok in hardware (embedded))
	//sleep makes less portable - depends on response on computer for rest of code
    data.push_back(42); // 3 //happens before 4
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