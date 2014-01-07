#ifndef __LOCKING_CACHE_STRATEGY_H
#define __LOCKING_CACHE_STRATEGY_H

#include <mutex>
#include "cache_strategy.h"

class locking_cache_strategy_helper : public cache_strategy_helper
{
public:
    locking_cache_strategy_helper();
private:
    std::mutex mutex_;
    std::lock_guard<std::mutex> lock_;
};

class locking_cache_strategy :public cache_strategy
{
public:
    std::unique_ptr<cache_strategy_helper> during_cache_access() override;
};

#endif // __LOCKING_CACHE_STRATEGY_H