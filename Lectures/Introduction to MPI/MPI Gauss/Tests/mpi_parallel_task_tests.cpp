#include "gtest/gtest.h"
#include "../Library/mpi_parallel_task.h"
#include "partitioning_tracker.h"
#include "mock_task.h"
#include "mock_mpi_adapter.h"
#include "partitioning_functions.h"

TEST(MpiParallelTaskTests, StartCallsPartitioningFunction)
{
    PartitioningTracker tracker;

    auto partitioning_method = std::bind(&PartitioningTracker::partition, &tracker, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

    MockTask task;
    MockMpiAdapter mpiAdapter;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, partitioning_method, 1);

    runner.start();

    ASSERT_EQ(true, tracker.GetPartitioningMethodCalled()) << "The partitioning method was not called, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsPartitioningFunctionWithBeginInteger)
{
    PartitioningTracker tracker;

    auto partitioning_method = std::bind(&PartitioningTracker::partition, &tracker, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

    const int begin = 17;

    MockTask task;
    MockMpiAdapter mpiAdapter;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, begin, 1, partitioning_method, 1);

    runner.start();

    ASSERT_EQ(begin, tracker.GetBeginInteger()) << "The partitioning method was not called with the begin iterator, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsPartitioningFunctionWithEndInteger)
{
    PartitioningTracker tracker;

    auto partitioning_method = std::bind(&PartitioningTracker::partition, &tracker, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

    const int end = 49;

    MockTask task;
    MockMpiAdapter mpiAdapter;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0, end, partitioning_method, 1);

    runner.start();

    ASSERT_EQ(end, tracker.GetEndInteger()) << "The partitioning method was not called with the end iterator, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsPartitioningFunctionWithNumberOfPartitions)
{
    PartitioningTracker tracker;

    auto partitioning_method = std::bind(&PartitioningTracker::partition, &tracker, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);

    MockTask task;
    MockMpiAdapter mpiAdapter;
    const int number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, partitioning_method, number_of_partitions);

    runner.start();

    ASSERT_EQ(number_of_partitions, tracker.GetNumberOfPartitions()) << "The partitioning method was not called with the number of partitions, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiSendOnceForTwoPartitions)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, two_partitions, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(1, mpiAdapter.GetNumberOfTimesMpiSendCalled()) << "The MPI_Send method was not called the correct number of times based on the given number of partitions, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiSendTwiceForThreePartitions)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, three_partitions, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(2, mpiAdapter.GetNumberOfTimesMpiSendCalled()) << "The MPI_Send method was not called the correct number of times based on the given number of partitions, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiSendWithTheCorrectNumberOfEntriesForThePartitions)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, two_partitions, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(2, mpiAdapter.GetCountInMpiSend()) << "The MPI_Send method was not called with the correct count of elements based on the given number of partitions, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiSendWithTheExpectedTag)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, two_partitions, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(0, mpiAdapter.GetTagInMpiSend()) << "The MPI_Send method was not called with the expected tag, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiSendWithTheStartIntegerForThePartition)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 67U, 92U, two_partitions, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(67U, mpiAdapter.GetFirstIntegerValueInMpiSend()) << "The MPI_Send method was not called the correct first iterator value, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiSendWithTheEndIntegerForThePartition)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 67U, 92U, two_partitions, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(92U, mpiAdapter.GetSecondIntegerValueInMpiSend()) << "The MPI_Send method was not called the correct end iterator value, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiSendWithRankDestinationOneForTheSecondPartition)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, two_partitions_from_four_items, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(1, mpiAdapter.GetDestinationInMpiSend()) << "The MPI_Send method was not called the correct destination, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiRecvForNonRankZeroInstances)
{
    MockTask task;
    MockMpiAdapter mpiAdapter(4);

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, one_partition, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(true, mpiAdapter.GetMpiRecvCalled()) << "The MPI_Recv method was not called for a non-rank-zero intance, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiRecvForNonRankZeroInstancesWithExpectedCount)
{
    MockTask task;
    MockMpiAdapter mpiAdapter(4);

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, one_partition, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(2, mpiAdapter.GetCountInMpiRecv()) << "The MPI_Recv method was not called for a non-rank-zero intance with the expected count, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiRecvForNonRankZeroInstancesWithExpectedSource)
{
    MockTask task;
    MockMpiAdapter mpiAdapter(4);

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, one_partition, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(0, mpiAdapter.GetSourceInMpiRecv()) << "The MPI_Recv method was not called for a non-rank-zero intance with the expected source, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiRecvForNonRankZeroInstancesWithExpectedTag)
{
    MockTask task;
    MockMpiAdapter mpiAdapter(4);

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, one_partition, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(0, mpiAdapter.GetTagInMpiRecv()) << "The MPI_Recv method was not called for a non-rank-zero intance with the expected tag, which is not expected.";
}

TEST(MpiParallelTaskTests, StartDoesNotCallMpiRecvForRankZeroInstances)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, one_partition, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(false, mpiAdapter.GetMpiRecvCalled()) << "The MPI_Recv method was called for a rank-zero intance, which is not expected.";
}

TEST(MpiParallelTaskTests, StartDoesNotCallMpiSendForRankZeroInstances)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, one_partition, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(false, mpiAdapter.GetMpiSendCalled()) << "The MPI_Send method was called for a rank-zero intance, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMapOnProvidedTaskInstanceWithProperBeginValue)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 67U, 92U, one_partition, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(67U, task.GetBeginValue()) << "The map method on the task was not called with the proper begin iterator value, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMapOnProvidedTaskInstanceWithProperEndValue)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 67U, 92U, one_partition, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(92U, task.GetEndValue()) << "The map method on the task was not called with the proper end iterator value, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMapOnNewTaskInstanceWithProperBeginValueForSecondPartition)
{
    MockTask task;
    MockMpiAdapter mpiAdapter(1);

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, two_partitions, unused_number_of_partitions);

    task.ClearLatestValuesFromAnyInstance();

    runner.start();

    // The expected value is supplied directly from the mock MPI_Recv method.
    ASSERT_EQ(67U, task.GetLatestBeginValueFromAnyInstance()) << "The map method on the task was not called with the proper begin iterator value, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMapOnNewTaskInstanceWithProperEndValueForSecondPartition)
{
    MockTask task;
    MockMpiAdapter mpiAdapter(1);

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, two_partitions, unused_number_of_partitions);

    task.ClearLatestValuesFromAnyInstance();

    runner.start();

    // The expected value is supplied directly from the mock MPI_Recv method.
    ASSERT_EQ(92U, task.GetLatestEndValueFromAnyInstance()) << "The map method on the task was not called with the proper end iterator value, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsReduceOnNewTaskInstanceWithZeroValueForInput)
{
    MockTask task;
    MockMpiAdapter mpiAdapter(1);

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, two_partitions, unused_number_of_partitions);

    task.ClearLatestValuesFromAnyInstance();

    runner.start();

    ASSERT_EQ(0U, task.GetLatestReduceInputValueFromAnyInstance()) << "The reduce method on the slave task was not called with zero input value, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiSendForRankOneProcessWithACountOfOneValue)
{
    MockTask task;
    MockMpiAdapter mpiAdapter(1);

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, two_partitions, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(1, mpiAdapter.GetCountInMpiSend()) << "The MpiSend method was not called with a count of one value, which is not expected.";
}

TEST(MpiParallelTaskTests, StartCallsMpiSendForRankOneProcessWithADestinationOfZero)
{
    MockTask task;
    MockMpiAdapter mpiAdapter(1);

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, two_partitions, unused_number_of_partitions);

    runner.start();

    ASSERT_EQ(0, mpiAdapter.GetDestinationInMpiSend()) << "The MpiSend method was not called with a destination of zero, which is not expected.";
}

TEST(MpiParallelTaskTests, CompleteCallsMpiRecvForRankZeroProcessWithACountOfOne)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, one_partition, unused_number_of_partitions);

    runner.complete();

    ASSERT_EQ(1, mpiAdapter.GetCountInMpiRecv()) << "The MpiRecv method was not called with a count of one, which is not expected.";
}

TEST(MpiParallelTaskTests, CompleteDoesNotCallMpiRecvForANonRankZeroProcess)
{
    MockTask task;
    MockMpiAdapter mpiAdapter(3);

    const int unused_number_of_partitions = 13;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, one_partition, unused_number_of_partitions);

    runner.complete();

    ASSERT_EQ(false, mpiAdapter.GetMpiRecvCalled()) << "The MpiRecv method was called for a non-rank 0 process, which is not expected.";
}

TEST(MpiParallelTaskTests, CompleteCallsMpiRecvForRankZeroProcessWithASourceForEachSlaveProcess)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int number_of_partitions = 6;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, one_partition, number_of_partitions);

    runner.complete();

    ASSERT_EQ(5, mpiAdapter.GetNumberOfTimesMpiRecvCalled()) << "The MpiRecv method was not called for five slave nodes, which is not expected.";
    ASSERT_EQ(1, mpiAdapter.GetSourcesInMpiRecv()[0]) << "The MpiRecv method was not called for slave node 1, which is not expected.";
    ASSERT_EQ(2, mpiAdapter.GetSourcesInMpiRecv()[1]) << "The MpiRecv method was not called for slave node 2, which is not expected.";
    ASSERT_EQ(3, mpiAdapter.GetSourcesInMpiRecv()[2]) << "The MpiRecv method was not called for slave node 3, which is not expected.";
    ASSERT_EQ(4, mpiAdapter.GetSourcesInMpiRecv()[3]) << "The MpiRecv method was not called for slave node 4, which is not expected.";
    ASSERT_EQ(5, mpiAdapter.GetSourcesInMpiRecv()[4]) << "The MpiRecv method was not called for slave node 5, which is not expected.";
}

TEST(MpiParallelTaskTests, CompleteCallsReduceOnTheOriginalTaskForRankZeroProcessWithTheOutputValueFromMpiRecvForEachSlaveProcess)
{
    MockTask task;
    MockMpiAdapter mpiAdapter;

    const int number_of_partitions = 2;
    auto runner = MpiParallelTask<MockTask>(task, mpiAdapter, 0U, 1U, one_partition, number_of_partitions);

    runner.complete();

    // The expected value comes directly from the MockMpiAdapter implementation.
    ASSERT_EQ(67U, task.GetReduceInputValue()) << "The reduce method was not called with the correct reduce input value solutions, which is not expected.";
}
