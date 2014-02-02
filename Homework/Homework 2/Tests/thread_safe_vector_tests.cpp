#include "gtest/gtest.h"
#include "thread_safe_vector.h"
#include "mock_mutex.h"

TEST(ThreadSafeVectorTests, InitialSizeIsZero)
{
    thread_safe_vector<int> container;

    ASSERT_EQ(0, container.size());
}

TEST(ThreadSafeVectorTests, SizeEqualsOne)
{
	thread_safe_vector<int> container;
	container.push_back(12);
	ASSERT_EQ(1, container.size());
}

TEST(ThreadSafeVectorTests, EnqueueTheFirstItem)
{
	thread_safe_vector<int> container;
	container.push_back(12);
	ASSERT_EQ(12, container.at(0));
}

TEST(ThreadSafeVectorTests, EnqueueTheSecondItem)
{
	thread_safe_vector<int> container;
	container.push_back(12);
	container.push_back(20);
	ASSERT_EQ(20, container.at(1));
}

TEST(ThreadSafeVectorTests, SizeEqualsTwo)
{
	thread_safe_vector<int> container;
	container.push_back(12);
	container.push_back(20);
	ASSERT_EQ(2, container.size());
}

TEST(ThreadSafeVectorTests, IndexOutOfRange)
{
	thread_safe_vector<int> container;
	ASSERT_THROW(container.at(10), std::invalid_argument);
}


class VectorLockingTests : public ::testing::Test
{
protected:
	virtual void TearDown()
	{
		m_.clear_lock_trackers();
	}
	mock_mutex m_;
};

TEST_F(VectorLockingTests, PushLockTaken)
{
	thread_safe_vector_<int, mock_mutex> container;
	container.push_back(12);
	ASSERT_TRUE(m_.lock_called());
}

TEST_F(VectorLockingTests, PushLockReleased)
{
	thread_safe_vector_<int, mock_mutex> container;
	container.push_back(12);
	ASSERT_TRUE(m_.unlock_called());
}

TEST_F(VectorLockingTests, AtTakesLock)
{
	thread_safe_vector_<int, mock_mutex> container;
	container.push_back(12);
	m_.clear_lock_trackers();
	container.at(0);
	ASSERT_TRUE(m_.lock_called());
}

TEST_F(VectorLockingTests, AtReleaseLock)
{
	thread_safe_vector_<int, mock_mutex> container;
	container.push_back(12);
	m_.clear_lock_trackers();
	container.at(0);
	ASSERT_TRUE(m_.unlock_called());
}

TEST_F(VectorLockingTests, SizeTakesLock)
{
	thread_safe_vector_<int, mock_mutex> container;
	container.push_back(12);
	m_.clear_lock_trackers();
	container.size();
	ASSERT_TRUE(m_.lock_called());
}

TEST_F(VectorLockingTests, SizeReleasesLock)
{
	thread_safe_vector_<int, mock_mutex> container;
	container.push_back(12);
	m_.clear_lock_trackers();
	container.size();
	ASSERT_TRUE(m_.unlock_called());
}


