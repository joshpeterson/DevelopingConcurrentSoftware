#include "pi_calculator.h"
#include <cmath>
#include <condition_variable>

// Implementation using the Leibniz formula, idea from
// http://goparallel.sourceforge.net/calculate-pi-with-custom-c-class/

calculate_pi::calculate_pi() :
    exit_condition_(nullptr), should_exit_(nullptr)
{
}

calculate_pi::calculate_pi(std::condition_variable* exit_condition, bool* should_exit) :
    exit_condition_(exit_condition), should_exit_(should_exit)
{
}

double calculate_pi::operator()(int number_of_iterations)
{
    double quarter_of_pi = 0.0;
    for (auto n = 0; n < number_of_iterations; ++n)
    {
        auto numerator = pow(-1, n);
        auto denominator = 2 * n + 1;
        auto quotient = numerator / denominator;
        quarter_of_pi += quotient;

        if (n % 10 == 0 && exit_condition_ != nullptr && should_exit_ != nullptr)
        {
            std::mutex m;
            std::unique_lock<std::mutex> lk(m);
            if (exit_condition_->wait_for(lk, std::chrono::milliseconds(0), [this]{return *should_exit_;}))
                if (*should_exit_)
                    return 4.0 * quarter_of_pi;
        }
    }

    return 4.0 * quarter_of_pi;
}