#include "gtest/gtest.h"
#include "reference_counted.h"
#include "mock_class.h"

class ReferenceCountedTests : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		mock_class::clear_trackers(); //initialize static values to false
	}

	virtual void TearDown()
	{
		mock_class::clear_trackers();
	}

	mock_class c_;
};

TEST_F(ReferenceCountedTests, ConstructorCalledOnInitialization)
{
	reference_counted<mock_class> ref(c_);

	ASSERT_TRUE(mock_class::constructor_called());
}

TEST_F(ReferenceCountedTests, DestructorCalledAfterOneRelease)
{
	reference_counted<mock_class> ref(c_);
	ref.add_reference();
	ref.release();

	ASSERT_TRUE(mock_class::destructor_called());
}

TEST_F(ReferenceCountedTests, DestructorNotCalledUntilReferenceCountIsZero)
{
	reference_counted<mock_class> ref(c_);
	ref.add_reference();
	ref.add_reference();
	ref.release();

	ASSERT_FALSE(mock_class::destructor_called());
}


TEST_F(ReferenceCountedTests, DestructorCalledAfterThreeReleases)
{
	reference_counted<mock_class> ref(c_);
	ref.add_reference();
	ref.add_reference();
	ref.release();
	ref.add_reference();
	ref.release();
	ref.release();

	ASSERT_TRUE(mock_class::destructor_called());
}

