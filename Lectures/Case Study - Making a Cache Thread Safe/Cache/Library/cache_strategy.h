#ifndef __CACHE_STRATEGY_H
#define __CACHE_STRATEGY_H

#include <memory>

class cache_strategy_helper
{
};

class cache_strategy
{
public:
    virtual std::unique_ptr<cache_strategy_helper> during_cache_access() = 0;
};

#endif // __CACHE_STRATEGY_H