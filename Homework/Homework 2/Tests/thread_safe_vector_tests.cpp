#include "gtest/gtest.h"
#include "thread_safe_vector.h"
#include "thread"

TEST(ThreadSafeVectorTests, InitialSizeIsZero)
{
    thread_safe_vector<int> container;

    ASSERT_EQ(0, container.size());
}

//realized that in order to test the accessors, I needed to have some way of changing what they were initialized to.

TEST(ThreadSafeVectorTests, ThreeItemVectorHasSizeThree)
{
	std::vector<int> dummy = { 1, 2, 3 };
	thread_safe_vector<int> container(dummy);

	ASSERT_EQ(3, container.size());
}

TEST(ThreadSafeVectorTests, AtFunctionGrantsRandomAccess)
{
	std::vector<int> dummy = {1, 2, 3};

	thread_safe_vector<int> container(dummy);

	ASSERT_EQ(1, container.at(0));
	ASSERT_EQ(2, container.at(1));
	ASSERT_EQ(3, container.at(2));
}

TEST(ThreadSafeVectorTests, PushBackIncreasesSize)
{
	thread_safe_vector<int> container;

	container.push_back(1);

	ASSERT_EQ(1, container.size());
}

//at and size use Read-Only memory, so we don't need to test
//This test really doesn't do anything.  I talked to three other members of class and wasn't able to 
//come up with a test that could reliably fail.  I knew what I had to do to make a thread safe vector
//so I just did this and made a safe thread class.

TEST(ThreadSafeVectorTests, Pushback_ThreadCompatability)
{
	std::vector<int> dummy = { 1, 2, 3 };
	thread_safe_vector<int> container(dummy);

	std::thread test1(&thread_safe_vector<int>::push_back, std::ref(container), 4);
	std::thread test2(&thread_safe_vector<int>::push_back, std::ref(container), 5);

	test1.join();
	test2.join();

	ASSERT_EQ(1, container.at(0));
	ASSERT_EQ(2, container.at(1));
	ASSERT_EQ(3, container.at(2));
	ASSERT_EQ(4, container.at(3));
	ASSERT_EQ(5, container.at(4));

}