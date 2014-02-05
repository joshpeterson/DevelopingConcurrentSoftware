#include "gtest/gtest.h"
#include "mock_mutex.h"
#include "thread_safe_vector.h"

TEST(ThreadSafeVectorTests, InitialSizeIsZero)
{
    thread_safe_vector<int> container;

    ASSERT_EQ(0, container.size());
}

TEST(ThreadSafeVectorTests, SizeIsOneAfterOnePushBackCall)
{
    thread_safe_vector<int> container;
    container.push_back(42);

    ASSERT_EQ(1, container.size());
}

TEST(ThreadSafeVectorTests, AtObtainsValueAtIndexZero)
{
    thread_safe_vector<int> container;
    container.push_back(42);

    ASSERT_EQ(42, container.at(0));
}

class ThreadSafeVectorLockingTests : public ::testing::Test
{
protected:
    virtual void TearDown()
    {
        m_.clear_lock_trackers();
    }

    mock_mutex m_;
};

TEST_F(ThreadSafeVectorLockingTests, PushBackMethodTakesTheLock)
{
    thread_safe_vector_<int, mock_mutex> container;
    container.push_back(512);

    ASSERT_TRUE(m_.lock_called()) << "The push_back method did not take the lock, which is not expected.";
}

TEST_F(ThreadSafeVectorLockingTests, PushBackMethodReleasesTheLock)
{
    thread_safe_vector_<int, mock_mutex> container;
    container.push_back(512);

    ASSERT_TRUE(m_.unlock_called()) << "The push_back method did not take the lock, which is not expected.";
}

TEST_F(ThreadSafeVectorLockingTests, AtMethodTakesTheLock)
{
    thread_safe_vector_<int, mock_mutex> container;
    container.push_back(512);
    m_.clear_lock_trackers();

    container.at(0);

    ASSERT_TRUE(m_.lock_called()) << "The at method did not take the lock, which is not expected.";
}

TEST_F(ThreadSafeVectorLockingTests, AtMethodReleasesTheLock)
{
    thread_safe_vector_<int, mock_mutex> container;
    container.push_back(512);
    m_.clear_lock_trackers();

    container.at(0);

    ASSERT_TRUE(m_.unlock_called()) << "The at method did not take the lock, which is not expected.";
}

TEST_F(ThreadSafeVectorLockingTests, SizeMethodTakesTheLock)
{
    thread_safe_vector_<int, mock_mutex> container;
    container.push_back(512);
    m_.clear_lock_trackers();

    container.size();

    ASSERT_TRUE(m_.lock_called()) << "The size method did not take the lock, which is not expected.";
}

TEST_F(ThreadSafeVectorLockingTests, SizeMethodReleasesTheLock)
{
    thread_safe_vector_<int, mock_mutex> container;
    container.push_back(512);
    m_.clear_lock_trackers();

    container.size();

    ASSERT_TRUE(m_.unlock_called()) << "The size method did not take the lock, which is not expected.";
}