#ifndef __LOCKING_CACHE_STRATEGY_H
#define __LOCKING_CACHE_STRATEGY_H

#include <mutex>
#include "cache_strategy.h"

template<typename T>
class locking_cache_strategy_helper_ : public cache_strategy_helper
{
public:
	locking_cache_strategy_helper_() : lock_(mutex_) {}
private:
    T mutex_;
    std::lock_guard<T> lock_;
};

typedef locking_cache_strategy_helper_<std::mutex> locking_cache_strategy_helper;


class locking_cache_strategy :public cache_strategy
{
public:
    std::unique_ptr<cache_strategy_helper> during_cache_access() override;
};


#endif // __LOCKING_CACHE_STRATEGY_H