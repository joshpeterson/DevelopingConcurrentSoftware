#include "gtest/gtest.h"
#include "../Library/mpi_word_counter.h"

TEST(MpiWordCounterTests, GetCountReturnsZeroByDefault)
{
    mpi_word_counter counter("unused", std::vector<std::string>());
    ASSERT_EQ(0, counter.get_count());
}