#ifndef __GUASS_TASK_H
#define __GAUSS_TASK_H

#include <vector>

class gauss_task
{
public:
    gauss_task();
    void map(unsigned int begin, unsigned int end);
    std::vector<unsigned int> reduce(const std::vector<unsigned int>& input);
private:
    unsigned int sum_;
};

#endif // __GAUSS_TASK_H