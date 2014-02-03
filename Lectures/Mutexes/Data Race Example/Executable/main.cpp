#include <iostream>
#include <thread>
//protecting
#include<mutex>
std::mutex m;
int shared;

void reader()//reads
{
	m.lock();
    std::cout << "The value of shared is: " << shared << std::endl;
	m.unlock(); //now no longer a data race on shared
}

void writer()//writes a million times
{
	m.lock();
    for (int i = 0; i < 1000000; ++i)
        shared++;
	m.unlock();
}

int main()
{
    shared = 3;//this is the subject of one data race

    std::thread writer_thread(writer);//creating 2 threads
    std::thread reader_thread(reader);

    writer_thread.detach();//letting them run without any synchronization
    reader_thread.detach();

    std::cout << "Press any key to continue...\n"; //this is also a race - on cout
	//ideally, we can protect cout 
    std::getchar();
	//prints out how many times the writer got to it before the reader
	//every time, we get different behavior
	//sometimes a million + 3 (max number)
	//since it's not synchronized, whatever happens happens
}

//with mutex
// could either get 3 or max (we seem to be tending to get max)
//the reader could actually execute before the writer

//if cout throws an exception, then unlock never happens!