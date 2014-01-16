#ifndef __NULL_CACHE_STRATEGY_H
#define __NULL_CACHE_STRATEGY_H

#include "cache_strategy.h"

class null_cache_strategy : public cache_strategy
{
public:
    std::unique_ptr<cache_strategy_helper> during_cache_access() override;
};

#endif // __NULL_CACHE_STRATEGY_H