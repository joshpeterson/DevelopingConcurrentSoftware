#include "gtest/gtest.h"
#include "reference_counted.h"

TEST(ReferenceCountedTests, DefaultIsZero)
{
	reference_counted<int> counter(42);
	ASSERT_EQ(0, counter.get_count());
}

TEST(ReferenceCountedTests, AddOneReferenceIsOne)
{
	reference_counted<int> counter(42);
	counter.add_reference();
	ASSERT_EQ(1, counter.get_count());
}

TEST(ReferenceCountedTests, AddOneReferenceAndRemoveOneIsZero)
{
	reference_counted<int> counter(42);
	counter.add_reference();
	counter.release();
	ASSERT_EQ(0, counter.get_count());
}

TEST(ReferenceCountedTests, RemoveOneFromZeroIsNegativeOne)
{
	reference_counted<int> counter(42);
	counter.release();
	ASSERT_EQ(-1, counter.get_count());
}

TEST(ReferenceCountedTests, GetValue) 
{
	reference_counted<int> counter(42);
	ASSERT_EQ(42, counter.get_value());
}

TEST(ReferenceCountedTests, GetValueAddOneReference)
{
	reference_counted<int> counter(42);
	counter.add_reference();
	ASSERT_EQ(42, counter.get_value());
}

TEST(ReferenceCountedTests, NetRemoveAllValues) 
{
	reference_counted<int> counter(42);
	counter.add_reference();
	counter.release();
	counter.release();
	ASSERT_EQ(42, counter.get_value());		// Expect failure because reference becomes invalid 
}

//hi