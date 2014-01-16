#include "locking_cache_strategy.h"

locking_cache_strategy_helper::locking_cache_strategy_helper() : lock_(mutex_)
{
}

std::unique_ptr<cache_strategy_helper> locking_cache_strategy::during_cache_access()
{
    return std::unique_ptr<locking_cache_strategy_helper>(new locking_cache_strategy_helper);
}