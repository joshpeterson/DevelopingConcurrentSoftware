#include "gtest/gtest.h"
#include "../Library/even_partitioning_of_consecutive_integers.h"

TEST(EventPartitioningOfConsecutiveIntegersTests, ReturnsNoPartitionsWhenBeginAndEndAreTheSame)
{
    auto partitions = even_partitioning_of_consecutive_integers(42, 42, 12);

    ASSERT_EQ(0U, partitions.size()) << "The even partitioning returned at least one paritition when begin and end are the same, which is not expected.";
}

TEST(EventPartitioningOfConsecutiveIntegersTests, SplitsAnEvenNumberOfIntegersIntoAnEvenNumberOfPartitions)
{
    auto partitions = even_partitioning_of_consecutive_integers(1, 4, 2);
    ASSERT_EQ(2U, partitions.size()) << "The number of partitions is not 2, which is not expected.";
}

TEST(EventPartitioningOfConsecutiveIntegersTests, ReturnsTheCorrectFirstPartitionForAnEvenNumberOfIntegersAndAnEvenNumberOfPartitions)
{
    auto partitions = even_partitioning_of_consecutive_integers(1, 4, 2);

    ASSERT_EQ(1U, partitions[0].first) << "The begin value of the first partition is not 1, which is not expected.";
    ASSERT_EQ(2U, partitions[0].second) << "The end value of the first partition is not 2, which is not expected.";
}

TEST(EventPartitioningOfConsecutiveIntegersTests, ReturnsTheCorrectSecondPartitionForAnEvenNumberOfIntegersAndAnEvenNumberOfPartitions)
{
    auto partitions = even_partitioning_of_consecutive_integers(10, 30, 4);

    ASSERT_EQ(15U, partitions[1].first) << "The begin value of the second partition is not 15, which is not expected.";
    ASSERT_EQ(19U, partitions[1].second) << "The end value of the second partition is not 19, which is not expected.";
}

TEST(EventPartitioningOfConsecutiveIntegersTests, SplitsAnEvenNumberOfIntegersIntoAnOddNumberOfPartitions)
{
    auto partitions = even_partitioning_of_consecutive_integers(1, 10, 3);

    ASSERT_EQ(3U, partitions.size()) << "The number of partitions is not 3, which is not expected.";
}

TEST(EventPartitioningOfConsecutiveIntegersTests, ReturnsTheCorrectFirstPartitionForAnEvenNumberOfIntegersAndAnOddNumberOfPartitions)
{
    auto partitions = even_partitioning_of_consecutive_integers(1, 10, 3);

    ASSERT_EQ(1U, partitions[0].first) << "The begin value of the first partition is not 1, which is not expected.";
    ASSERT_EQ(3U, partitions[0].second) << "The end value of the first partition is not 3, which is not expected.";
}

TEST(EventPartitioningOfConsecutiveIntegersTests, ReturnsTheCorrectSecondPartitionForAnEvenNumberOfIntegersAndAnOddNumberOfPartitions)
{
    auto partitions = even_partitioning_of_consecutive_integers(1, 10, 3);

    ASSERT_EQ(4U, partitions[1].first) << "The begin value of the first partition is not 4, which is not expected.";
    ASSERT_EQ(6U, partitions[1].second) << "The end value of the first partition is not 6, which is not expected.";
}

TEST(EventPartitioningOfConsecutiveIntegersTests, ReturnsTheCorrectThirdPartitionForAnEvenNumberOfIntegersAndAnOddNumberOfPartitions)
{
    auto partitions = even_partitioning_of_consecutive_integers(1, 10, 3);

    ASSERT_EQ(7U, partitions[2].first) << "The begin value of the first partition is not 7, which is not expected.";
    ASSERT_EQ(10U, partitions[2].second) << "The end value of the first partition is not 10, which is not expected.";
}

TEST(EventPartitioningOfConsecutiveIntegersTests, ReturnsTheCorrectThirdPartitionForAnOddNumberOfIntegersAndAnOddNumberOfPartitions)
{
    auto partitions = even_partitioning_of_consecutive_integers(1, 11, 3);

    ASSERT_EQ(7U, partitions[2].first) << "The begin value of the first partition is not 7, which is not expected.";
    ASSERT_EQ(11U, partitions[2].second) << "The end value of the first partition is not 11, which is not expected.";
}
