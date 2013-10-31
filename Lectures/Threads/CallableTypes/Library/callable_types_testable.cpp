#include <iostream>
#include "callable_types_testable.h"

namespace callable_types_testable
{

    void free_function(std::ostream& out)
    {
        std::cout << "Free function\n";
    }

    void functor::operator()(std::ostream& out) const
    {
        std::cout << "Functor\n";
    }

    void example::member_function(std::ostream& out) const
    {
        std::cout << "Member function\n";
    }

}