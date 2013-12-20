#ifndef __COMMAND_H
#define __COMMAND_H

#include <memory>
#include "matrix.h"

namespace osoasso
{

class command
{
public:
    virtual std::shared_ptr<const matrix<double>> call(std::shared_ptr<const matrix<double>> left, std::shared_ptr<const matrix<double>> right,
                                                       int number_of_threads) const = 0;
    virtual int number_of_arguments() const = 0;
    virtual std::string get_help() const = 0;
};

}

#endif // __COMMAND_H
