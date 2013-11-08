#include"gauss.h"
#include "producer_consumer_queue.h"

void gauss(producer_consumer_queue& queue, int& sum)
{
    sum = 0;

    int value;
    while(queue.try_dequeue(value))
        sum += value;
}