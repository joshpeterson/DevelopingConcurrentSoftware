#include "gtest/gtest.h"
#include "hello.h"

TEST(HelloTests, ReturnsHelloWorldMessage)
{
    ASSERT_EQ("Hello, world!\n", library::get_message()) << "The expected message was not provided.";
}