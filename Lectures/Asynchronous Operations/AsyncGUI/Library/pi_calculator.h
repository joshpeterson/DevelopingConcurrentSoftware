#ifndef __PI_CALCULATOR_H
#define __PI_CALCULATOR_H

#include <condition_variable>
#include <mutex>

class calculate_pi
{
public:
    calculate_pi();
    calculate_pi(std::condition_variable* exit_condition, bool* should_exit);
    double operator()(int number_of_iterations);

private:
    std::condition_variable* exit_condition_;
    bool* should_exit_;
};

#endif // __PI_CALCULATOR_H