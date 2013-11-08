#include "gtest/gtest.h"
#include "producer_consumer_queue.h"
#include "gauss.h"

TEST(GaussTests, SumsAllNumbersInQueue)
{
    producer_consumer_queue queue;
    queue.enqueue(42);
    queue.enqueue(43);

    int result_sum = 0;
    gauss(queue, result_sum);

    ASSERT_EQ(85, result_sum);
}

TEST(GaussTests, ProducesAZeroSumForAnEmptyQueue)
{
    producer_consumer_queue queue;

    int result_sum;
    gauss(queue, result_sum);

    ASSERT_EQ(0, result_sum);
}