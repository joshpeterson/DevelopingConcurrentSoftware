#include "null_cache_strategy.h"

std::unique_ptr<cache_strategy_helper> null_cache_strategy::during_cache_access()
{
    return std::unique_ptr<cache_strategy_helper>(new cache_strategy_helper);
}