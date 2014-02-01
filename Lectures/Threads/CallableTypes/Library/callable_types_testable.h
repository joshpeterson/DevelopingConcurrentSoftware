#include <iosfwd>

namespace callable_types_testable
{
    void free_function(std::ostream& out);

    class functor
    {
    public:
        void operator()(std::ostream& out) const;
    };

    class example
    {
    public:
        void member_function(std::ostream& out) const;
    };

}