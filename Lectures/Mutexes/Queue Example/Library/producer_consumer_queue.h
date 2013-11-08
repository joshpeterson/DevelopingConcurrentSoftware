#ifndef __PRODCUER_CONSUMER_QUEUE_H
#define __PRODCUER_CONSUMER_QUEUE_H

#include <deque>
#include <mutex>

template<typename T>
class producer_consumer_queue_
{
public:
    void enqueue(int value)
    {
        std::lock_guard<T> guard(mutex_);
        deque_.push_back(value);
    }

    bool try_dequeue(int& value)
    {
        std::lock_guard<T> guard(mutex_);
        if (!deque_.empty())
        {
            value = deque_.front();
            deque_.pop_front();

            return true;
        }

        return false;
    }

    bool empty() const
    {
        std::lock_guard<T> guard(mutex_);
        return deque_.empty();
    }

private:
    std::deque<int> deque_;
    mutable T mutex_;

};

typedef producer_consumer_queue_<std::mutex> producer_consumer_queue;

#endif // __PRODCUER_CONSUMER_QUEUE_H