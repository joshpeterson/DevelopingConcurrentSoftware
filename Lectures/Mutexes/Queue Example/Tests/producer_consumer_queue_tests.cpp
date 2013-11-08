#include "gtest/gtest.h"
#include "producer_consumer_queue.h"
#include "mock_mutex.h"
#include <mutex>

TEST(ProducerConsumerQueueTests, DequeuesTheFirstItemOfTwoThatAreEnqueued)
{
    producer_consumer_queue queue;

    queue.enqueue(42);
    queue.enqueue(43);

    int front;
    queue.try_dequeue(front);

    ASSERT_EQ(42, front) << "The first value queued was not the first value dequeued, which is not expected.";
}

TEST(ProducerConsumerQueueTests, TheSecondDequeueReturnsTheSecondItemOfTwoThatAreEnqueued)
{
    producer_consumer_queue queue;

    queue.enqueue(42);
    queue.enqueue(43);

    int dummy;
    queue.try_dequeue(dummy);

    int front;
    queue.try_dequeue(front);

    ASSERT_EQ(43, front) << "The second value queued was not the second value dequeued, which is not expected.";
}

TEST(ProducerConsumerQueueTests, TryDequeueReturnsFalseWhenTheQueueIsEmpty)
{
    producer_consumer_queue queue;
    int dummy;

    ASSERT_FALSE(queue.try_dequeue(dummy)) << "The try_dequeue did not return false for an empty queue, which is not expected.";
}

TEST(ProducerConsumerQueueTests, EmptyReturnsTrueWhenTheQueueIsEmpty)
{
    producer_consumer_queue queue;
    ASSERT_TRUE(queue.empty()) << "The empty() method did not return true when the queue was empty, which is not expected.";
}

TEST(ProducerConsumerQueueTests, EmptyReturnsFalseWhenTheQueueIsNotEmpty)
{
    producer_consumer_queue queue;
    queue.enqueue(42);

    ASSERT_FALSE(queue.empty()) << "The empty() method did not return false when the queue was not empty, which is not expected.";
}

class ProducerConsumerQueueLockingTests : public ::testing::Test
{
protected:
    virtual void TearDown()
    {
        m_.clear_lock_trackers();
    }

    mock_mutex m_;
};

TEST_F(ProducerConsumerQueueLockingTests, EnqueueMethodTakesTheLock)
{
    producer_consumer_queue_<mock_mutex> queue;
    queue.enqueue(512);

    ASSERT_TRUE(m_.lock_called()) << "The enqueue method did not take the lock, which is not expected.";
}

TEST_F(ProducerConsumerQueueLockingTests, EnqueueMethodReleasesTheLock)
{
    producer_consumer_queue_<mock_mutex> queue;
    queue.enqueue(512);

    ASSERT_TRUE(m_.unlock_called()) << "The enqueue method did not release the lock, which is not expected.";
}

TEST_F(ProducerConsumerQueueLockingTests, DequeueMethodTakesTheLock)
{
    producer_consumer_queue_<mock_mutex> queue;
    queue.enqueue(512);

    m_.clear_lock_trackers();

    int dummy;
    queue.try_dequeue(dummy);

    ASSERT_TRUE(m_.lock_called()) << "The dequeue method did not take the lock, which is not expected.";
}

TEST_F(ProducerConsumerQueueLockingTests, DequeueMethodReleasesTheLock)
{
    producer_consumer_queue_<mock_mutex> queue;
    queue.enqueue(512);

    m_.clear_lock_trackers();

    int dummy;
    queue.try_dequeue(dummy);

    ASSERT_TRUE(m_.unlock_called()) << "The dequeue method did not release the lock, which is not expected.";
}

TEST_F(ProducerConsumerQueueLockingTests, EmptyMethodTakesTheLock)
{
    producer_consumer_queue_<mock_mutex> queue;
    queue.empty();

    ASSERT_TRUE(m_.lock_called()) << "The empty method did not take the lock, which is not expected.";
}

TEST_F(ProducerConsumerQueueLockingTests, EmptyMethodReleasesTheLock)
{
    producer_consumer_queue_<mock_mutex> queue;
    queue.empty();

    ASSERT_TRUE(m_.unlock_called()) << "The empty method did not release the lock, which is not expected.";
}