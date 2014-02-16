#include "gtest/gtest.h"
#include "reference_counted.h"

// Question
// Is it ok to add the accessor functions that I have added to the library in order to test?
// I found something in the GTest library that allows a Friend test, but I didn't look too much
// into it.

// I added an accessor that returns the current number of references,
// one that returns the current value of the value pointer,
// and one that returns the current value at the value pointer.

TEST(Ref_count_tests, default_return_0){
	reference_counted<int> tester(42);
	ASSERT_EQ(0, tester.get_number_of_references());
}

TEST(Ref_count_tests, Add_one_reference){
	reference_counted<int> tester(42);
	tester.add_reference();
	ASSERT_EQ(1, tester.get_number_of_references());
}

TEST(Ref_count_tests, Remove_one_reference){
	reference_counted<int> tester(42);
	tester.add_reference();
	tester.add_reference();
	tester.release();
	ASSERT_EQ(1, tester.get_number_of_references());
}

TEST(Ref_count_tests, set_value) {
	reference_counted<int> tester(45);
	ASSERT_EQ(45, tester.get_value());
}

TEST(Ref_count_tests, delete_value) {
	reference_counted<int> tester(50);
	tester.add_reference();
	tester.release();
	ASSERT_EQ(NULL, tester.is_null());
}

TEST(Ref_count_tests, negative_value) {
	reference_counted<int> tester(25);
	tester.add_reference();
	tester.release();
	tester.release();
	tester.release();
	ASSERT_EQ(0, tester.get_number_of_references());
}