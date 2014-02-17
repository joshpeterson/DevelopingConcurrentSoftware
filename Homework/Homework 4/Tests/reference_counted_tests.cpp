#include "gtest/gtest.h"
#include "reference_counted.h"

TEST(ReferenceCountedTests, DefaultZero)
{
	reference_counted<int> ref(27);
	ASSERT_EQ(0, ref.getCount());
}

TEST(ReferenceCountedTests, AddRef)
{
	reference_counted<int> ref(27);
	ref.add_reference();
	ASSERT_EQ(1, ref.getCount());
}

TEST(ReferenceCountedTests, ReleaseRef)
{
	reference_counted<int> ref(27);
	ref.add_reference();
	ref.release();
	ASSERT_EQ(0, ref.getCount());
}

TEST(ReferenceCountedTests, TestValAdded)
{
	reference_counted<int> ref(27);
	ref.add_reference();
	ASSERT_EQ(27, ref.getValue());
}