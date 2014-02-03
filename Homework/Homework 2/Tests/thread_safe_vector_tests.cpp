#include "gtest/gtest.h"
#include "thread_safe_vector.h"

#include <thread>
#include <stdlib.h>

TEST(ThreadSafeVectorTests, InitialSizeIsZero)
{
    thread_safe_vector<int> container;

    ASSERT_EQ(0, container.size());
}

TEST(ThreadSafeVectorTests, ConstructorSizeTest) {
	
	std::vector<int> hi = { 1, 2, 3 };
	thread_safe_vector<int> container(hi);

	ASSERT_EQ(3, container.size());
}

TEST(ThreadSafeVectorTests, ConstructorAtTest) {

	std::vector<int> hi = { 1, 2, 3 };
	thread_safe_vector<int> container(hi);

	ASSERT_EQ(2, container.at(1));
}


TEST(ThreadSafeVectorTests, ConstructorPushBackSizeTest) {

	std::vector<int> hi = { 1, 2, 3 };
	thread_safe_vector<int> container(hi);

	int a = container.size();
	container.push_back(4);
	ASSERT_EQ(a+1, container.size());

}

TEST(ThreadSafeVectorTests, PushBackAtAndSizeTest) {

	thread_safe_vector<int> container;

	container.push_back(1);
	container.push_back(2);
	container.push_back(3);
	container.push_back(4);

	ASSERT_EQ(4, container.at(3));
	ASSERT_EQ(3, container.at(2));
	ASSERT_EQ(4, container.size());
}


// Threading test:

// This test does not effectively test whether thread_safe_vector is actually thread-safe.
// However, this is the best that I can come up with. I am pretty sure that the class implements
// thread-safety properly, but I don't know how to test it.

void intpush(thread_safe_vector<int>& a, int b) {
	
	int r;
	srand(std::time(0));
	r = rand();
	//std::cout << "rand: " << r << std::endl;
	a.push_back(b);
	std::this_thread::sleep_for(std::chrono::milliseconds(r % 1000)); // from cppreference.com
}


// void valuerotation
TEST(ThreadSafeVectorTests, ThreadAtTest) {

	std::vector<int> hi = { 1, 2, 3, 4 };
	thread_safe_vector<int> container(hi);

	//std::thread t1(&thread_safe_vector<int>::push_back,5);
	//std::thread t2(&thread_safe_vector<int>::push_back,6);
	std::thread t1(intpush, std::ref(container), 5);
	std::thread t2(intpush, std::ref(container), 6);
	std::thread t3(intpush, std::ref(container), 7);
	std::thread t4(intpush, std::ref(container), 8);
	std::thread t5(intpush, std::ref(container), 9);
	std::thread t6(intpush, std::ref(container), 10);

	std::thread t7(&thread_safe_vector<int>::push_back, std::ref(container), 11);

	t1.detach();
	t2.detach();
	t3.detach();
	t4.detach();
	t5.detach();
	t6.detach();
	t7.detach();

	//t1.join();
	//t2.join();
	//t3.join();
	//t4.join();
	//t5.join();
	//t6.join();

	ASSERT_EQ(5, container.at(4));
	ASSERT_EQ(6, container.at(5));
	ASSERT_EQ(7, container.at(6));
	ASSERT_EQ(8, container.at(7));
	ASSERT_EQ(9, container.at(8));
	ASSERT_EQ(10, container.at(9));

	std::cout << "CONTENTS OF VARIABLE: ";
	for (int q = 0; q < container.size(); q++) {
		std::cout << container.at(q) << " ";
	}
	std::cout << std::endl;

}

