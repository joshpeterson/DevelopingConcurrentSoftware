#include "pi_calculator.h"
#include <cmath>

// Implementation using the Leibniz formula, idea from
// http://goparallel.sourceforge.net/calculate-pi-with-custom-c-class/

double calculate_pi(int number_of_iterations)
{
    double quarter_of_pi = 0.0;
    for (auto n = 0; n < number_of_iterations; ++n)
    {
        auto numerator = pow(-1, n);
        auto denominator = 2 * n + 1;
        auto quotient = numerator / denominator;
        quarter_of_pi += quotient;
    }

    return 4.0 * quarter_of_pi;
}