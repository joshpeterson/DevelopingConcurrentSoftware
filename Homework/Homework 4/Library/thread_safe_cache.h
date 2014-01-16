#ifndef __THREAD_SAFE_CACHE_H
#define __THREAD_SAFE_CACHE_H

#include <memory>
#include "cache.h"
#include "locking_cache_strategy.h"

template <typename TKey, typename TValue>
class thread_safe_cache : public cache<TKey, TValue>
{
public:
    thread_safe_cache() : cache(std::unique_ptr<cache_strategy>(new locking_cache_strategy))
    {
    }
};

#endif // __THREAD_SAFE_CACHE_H