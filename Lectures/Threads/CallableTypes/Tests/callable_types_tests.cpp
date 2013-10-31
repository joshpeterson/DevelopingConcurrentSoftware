#include <sstream>
#include "gtest/gtest.h"
#include "callable_types_testable.h"

using namespace callable_types_testable;

TEST(CallableTypesTests, FreeFunctionOutputsExpectedMessage)
{
	std::stringstream actual_message;
	free_function(actual_message);
    ASSERT_EQ("Free function\n", actual_message.str()) << "The expected message from free function was not provided.";
}

TEST(CallableTypesTests, FunctorOutputsExpectedMessage)
{
	std::stringstream actual_message;
	functor f;
	f(actual_message);
    ASSERT_EQ("Functor\n", actual_message.str()) << "The expected message from functor was not provided.";
}

TEST(CallableTypesTests, MemberFunctionOutputsExpectedMessage)
{
	std::stringstream actual_message;
	example e;
	e.member_function(actual_message);
    ASSERT_EQ("Member function\n", actual_message.str()) << "The expected message from member function was not provided.";
}