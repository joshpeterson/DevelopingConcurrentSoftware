#ifndef __GUASS_TASK_H
#define __GAUSS_TASK_H

#include <vector>

class gauss_task
{
public:
    gauss_task();
    void map(unsigned int begin, unsigned int end);
    unsigned int reduce(unsigned int input);

    int get_sum() const;
private:
    unsigned int sum_;
};

#endif // __GAUSS_TASK_H