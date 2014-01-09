#include "gauss_task.h"

gauss_task::gauss_task() : sum_(0) {}

void gauss_task::map(unsigned int begin, unsigned int end)
{
    for (auto i = begin; i <= end; ++i)
        sum_ += i;
}

unsigned int gauss_task::reduce(unsigned int input)
{
    sum_ += input;
    return sum_;
}

int gauss_task::get_sum() const
{
    return sum_;
}