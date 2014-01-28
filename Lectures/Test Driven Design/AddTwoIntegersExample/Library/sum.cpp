#include "sum.h"
#include <stdexcept>

namespace library
{
    int sum(int left, int right)
    {
        if (left < 0)
            throw std::invalid_argument("left");
        return left + right;
    }
}

