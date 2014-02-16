#include "gtest/gtest.h"
#include "reference_counted.h"


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