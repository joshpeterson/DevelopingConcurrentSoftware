#include "gtest/gtest.h"
#include "reference_counted.h"

class user_defined_type
{
public:
    user_defined_type()
    {
        default_constructor_called_ = true;
    }

    ~user_defined_type()
    {
        destructor_called_ = true;
    }

    user_defined_type& operator=(const user_defined_type& other)
    {
        assignment_operator_called_ = true;
        return *this;
    }

    bool get_default_constructor_called() const
    {
        return default_constructor_called_;
    }

    bool get_assignment_operator_called() const
    {
        return assignment_operator_called_;
    }

    bool get_destructor_called() const
    {
        return destructor_called_;
    }

    void clear_trackers()
    {
        default_constructor_called_ = false;
        assignment_operator_called_ = false;
        destructor_called_ = false;
    }

private:
    static bool default_constructor_called_;
    static bool assignment_operator_called_;
    static bool destructor_called_;
};

bool user_defined_type::default_constructor_called_ = false;
bool user_defined_type::assignment_operator_called_ = false;
bool user_defined_type::destructor_called_ = false;

class ReferenceCountedTests : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        type_to_test_.clear_trackers();
    }

    user_defined_type type_to_test_;
};

TEST_F(ReferenceCountedTests, ConstructorCreatesANewInstanceOfType)
{
    reference_counted<user_defined_type> udt(type_to_test_);
    ASSERT_TRUE(type_to_test_.get_default_constructor_called()) << "The default constructor was not called, which is not expected.";
}

TEST_F(ReferenceCountedTests, ConstructorAssignsTheInitialValueOfTheType)
{
    reference_counted<user_defined_type> udt(type_to_test_);
    ASSERT_TRUE(type_to_test_.get_assignment_operator_called()) << "The initial value of the type was not assigned, which is not expected.";
}

TEST_F(ReferenceCountedTests, ReleaseCallsUserDefinedTypeDestructor)
{
    reference_counted<user_defined_type> udt(type_to_test_);
    udt.add_reference();
    udt.release();
    ASSERT_TRUE(type_to_test_.get_destructor_called()) << "The destructor was not called, which is not expected.";
}

TEST_F(ReferenceCountedTests, ReleaseDoesNotCallUserDefinedTypeDestructorWhenReferenceCountIsNotZero)
{
    reference_counted<user_defined_type> udt(type_to_test_);
    udt.add_reference();
    udt.add_reference();
    udt.release();
    ASSERT_FALSE(type_to_test_.get_destructor_called()) << "The destructor was called, which is not expected.";
}

