#ifndef __CACHE_H
#define __CACHE_H

#include <map>
#include <functional>
#include <memory>
#include "cache_strategy.h"

// There is a compiler defect which prevents this code from compiling (#671343).
// http://stackoverflow.com/questions/16007178/why-passing-t-from-outer-template-as-default-argument-to-stdfunction-causes-co
#define VS_2013_COMPILER_DEFECT

#ifdef VS_2013_COMPILER_DEFECT
typedef std::string(*function_returning_string)();
#endif

template <typename TKey, typename TValue>
class cache
{
protected:
    cache(std::unique_ptr<cache_strategy> strategy) : strategy_(std::move(strategy))
    {
    }

public:
#ifdef VS_2013_COMPILER_DEFECT
    TValue get(TKey key, function_returning_string value_constructor)
#else
    TValue get(TKey key, std::function<TValue> value_constructor)
#endif
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
            result = value_in_cache->second;
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