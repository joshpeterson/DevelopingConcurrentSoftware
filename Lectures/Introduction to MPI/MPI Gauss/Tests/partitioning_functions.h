#ifndef __PARTITIONING_FUNCTIONS_H
#define __PARTITIONING_FUNCTIONS_H

#include <vector>

std::vector<std::pair<unsigned int, unsigned int>> one_partition(unsigned int begin, unsigned int end, int number_of_partitions)
{
    std::vector<std::pair<unsigned int, unsigned int>> output;
    output.emplace_back(std::make_pair(begin, end));

    return output;
}

std::vector<std::pair<unsigned int, unsigned int>> two_partitions(unsigned int begin, unsigned int end, int number_of_partitions)
{
    std::vector<std::pair<unsigned int, unsigned int>> output;
    output.emplace_back(std::make_pair(begin, end));
    output.emplace_back(std::make_pair(begin, end));
    return output;
}

std::vector<std::pair<unsigned int, unsigned int>> three_partitions(unsigned int begin, unsigned int end, int number_of_partitions)
{
    std::vector<std::pair<unsigned int, unsigned int>> output;
    output.emplace_back(std::make_pair(begin, end));
    output.emplace_back(std::make_pair(begin, end));
    output.emplace_back(std::make_pair(begin, end));
    return output;
}

std::vector<std::pair<unsigned int, unsigned int>> two_partitions_from_four_items(unsigned int begin, unsigned int end, int number_of_partitions)
{
    std::vector<std::pair<unsigned int, unsigned int>> output;

    output.emplace_back(std::make_pair(begin, begin + 1));
    output.emplace_back(std::make_pair(begin + 2, begin + 3));

    return output;
}

#endif // __PARTITIONING_FUNCTIONS_H
