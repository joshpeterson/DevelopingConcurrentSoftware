#include <stdexcept>
#include "sum.h"
#include <stdexcept>

namespace library
{
<<<<<<< HEAD
	int sum(int left, int right)
	{
		if (left < 0 || right < 0)
		{
			auto input_name = left < 0 ? "left" : "right";
			throw std::invalid_argument(std::string("The ") + input_name + std::string(" input cannot be negative."));
		}
		return left + right;
	}
=======
    int sum(int left, int right)
    {
        if (left < 0)
            throw std::invalid_argument("left");
        return left + right;
    }
>>>>>>> upstream/master
}

