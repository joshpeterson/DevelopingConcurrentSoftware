#include "locking_cache_strategy.h"

/*template<typename T>
locking_cache_strategy_helper_<T>::locking_cache_strategy_helper_() : lock_(mutex_)
{
}*/

std::unique_ptr<cache_strategy_helper> locking_cache_strategy::during_cache_access()
{
    return std::unique_ptr<locking_cache_strategy_helper>(new locking_cache_strategy_helper);
}