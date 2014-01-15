#include <iostream>
#include <vector>
#include <thread>
#include "thread_safe_vector.h"

const std::vector<double> source_data = { 3.14, 55.20, 9, -0.3381, 27.99087, 18, 72.4, 42, 16, -300.25 };

void copy_data_from_source(int source_begin_index, int source_end_index, thread_safe_vector<double>& output_data)
{
    for (auto i = source_begin_index; i <= source_end_index; ++i)
        output_data.push_back(source_data[i]);
}

int main()
{
    thread_safe_vector<double> data;

    std::thread data_processor1(copy_data_from_source, 0, 4, std::ref(data));
    std::thread data_processor2(copy_data_from_source, 5, 9, std::ref(data));

    data_processor1.join();
    data_processor2.join();

    auto data_size = data.size();
    if (data_size == source_data.size())
        std::cout << "Output data has correct size.\n";
    else
        std::cout << "Output data has incorrect size - expected : " << source_data.size() << " actual: " << data_size << std::endl;

    if (data_size == source_data.size())
    {
        auto all_data_matches = true;
        for (auto i = 0; i < data_size; ++i)
        {
            if (data.at(i) != source_data[i])
            {
                std::cout << "Output data at index " << i << " is incorrect - expected: " << source_data[i] << " actual: " << data.at(i) << std::endl;
                all_data_matches = false;
            }
        }

        if (all_data_matches)
            std::cout << "Content of output data is correct.\n";
    }

    std::cout << "Press any key to continue...\n";
    std::getchar();
}