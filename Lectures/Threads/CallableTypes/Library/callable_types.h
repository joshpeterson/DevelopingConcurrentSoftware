namespace callable_types
{

    void free_function();

    class functor
    {
    public:
        void operator()() const;
    };

    class example
    {
    public:
        void member_function() const;
    };
}