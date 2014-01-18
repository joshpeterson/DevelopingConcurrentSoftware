#ifndef __THREAD_NEURTRAL_CACHE_H
#define __THREAD_NEURTRAL_CACHE_H

#include <memory>
#include "cache.h"
#include "null_cache_strategy.h"

template <typename TKey, typename TValue>
class thread_neutral_cache : public cache<TKey, TValue>
{
public:
    thread_neutral_cache() : cache(std::unique_ptr<cache_strategy>(new null_cache_strategy))
    {
    }
};

#endif // __THREAD_NEURTRAL_CACHE_H