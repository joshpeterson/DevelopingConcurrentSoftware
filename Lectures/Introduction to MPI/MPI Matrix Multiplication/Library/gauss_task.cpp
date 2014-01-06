#include "gauss_task.h"

gauss_task::gauss_task() : sum_(0) {}

void gauss_task::map(unsigned int begin, unsigned int end)
{
    for (auto i = begin; i < end; ++i)
        sum_ += i;
}

std::vector<unsigned int> gauss_task::reduce(const std::vector<unsigned int>& input)
{
    std::vector<unsigned int> result;
    result.emplace_back(sum_);

    return result;
}