#include <iostream>
#include "callable_types.h"

namespace callable_types
{

void free_function()
{
	std::cout << "Free function\n";
}

void functor::operator()() const
{
	std::cout << "Functor\n";
}

void example::member_function() const
{
	std::cout << "Member function\n";
}

}
