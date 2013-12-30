#ifndef __CACHE_H
#define __CACHE_H

#include <map>
#include <functional>
#include <memory>
#include "cache_strategy.h"

template <typename TKey, typename TValue>
class cache
{
protected:
    cache(std::unique_ptr<cache_strategy> strategy) : strategy_(std::move(strategy))
    {
    }

public:
    TValue get(TKey key, std::function<TValue> value_constructor)
    {
        std::map<TKey, TValue>::iterator value_in_cache;
        TValue result;

        {
            auto helper = strategy_->during_cache_access();
            value_in_cache = cache_.find(key);
        }

        if (value_in_cache == cache_.end())
        {
            result = value_constructor();
            cache_[key] = result;
        }
        else
        {
            result = *value_in_cache;
        }

        return result;
    }

    void clear()
    {
        strategy_->during_cache_access();
        cache_.clear();
    }

private:
    std::unique_ptr<cache_strategy> strategy_;
    std::map<TKey, TValue> cache_;
};

#endif // __CACHE_H