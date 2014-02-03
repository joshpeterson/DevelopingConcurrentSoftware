#include "gtest/gtest.h"
#include "thread_safe_vector.h"
#include <thread>

//template <class T>
//void thread_safe_vector<T>::threadpusher(T value)
//{	
//	for (int i = 0; i < 1000; ++i)
//		container.push_back(4);
//	return;
//}
//
//int thread_safe_vector<T>::threadsizer(T value)
//{
//	return 
//}


TEST(ThreadSafeVectorTests, InitialSizeIsZero)
{
    thread_safe_vector<int> container;

    ASSERT_EQ(0, container.size());
}

TEST(ThreadSafeVectorTests, PushBackIncreasesSizeTo1)
{
	thread_safe_vector<int> container;
	container.push_back(0);
	ASSERT_EQ(1, container.size());
}

TEST(ThreadSafeVectorTests, PushBack2xIncreasesSizeTo2)
{
	thread_safe_vector<int> container;
	container.push_back(0);
	container.push_back(0);
	ASSERT_EQ(2, container.size());
}

TEST(ThreadSafeVectorTests, AtInvalidIndexThrows)
{
	thread_safe_vector<int> container;
	ASSERT_THROW(container.at(-1), std::out_of_range);
}

TEST(ThreadSafeVectorTests, PushBack0AllowsFinding0)
{
	thread_safe_vector<int> container;
	container.push_back(0);
	ASSERT_EQ(0, container.at(0));
}

TEST(ThreadSafeVectorTests, PushBack3AllowsFinding3)
{
	thread_safe_vector<int> container;
	container.push_back(3);
	ASSERT_EQ(3, container.at(0));
}


//TEST(ThreadSafeVectorTests, MultipleThreadsSizeIs100)
//{
//	thread_safe_vector<int> container; //subject of data race
//	std::thread size_thread();
//
//}


//TEST(ThreadSafeVectorTests, ThreadPusher)
//{
//	thread_safe_vector<int> container;
//	for (int i = 0; i < 1000; ++i)
//		container.push_back(4);
//	ASSERT_EQ(1000, container.size());
//}

TEST(ThreadSafeVectorTests, PushBackIsLocked)
{
	thread_safe_vector<int> container;

}


