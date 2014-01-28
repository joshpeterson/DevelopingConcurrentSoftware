#ifndef __MPI_PARALLEL_TASK_SCATTER_GATHER_H
#define __MPI_PARALLEL_TASK_SCATTER_GATHER_H

#include <functional>
#include <utility>
#include <vector>

#include "mpi_adapter_interface.h"

template <typename TaskType>
class MpiParallelTaskScatterGather
{
public:
    MpiParallelTaskScatterGather(TaskType& task, const MpiAdapterInterface& mpi_interface, unsigned int begin, unsigned int end,
        std::function<std::vector<std::pair<unsigned int, unsigned int>>(unsigned int, unsigned int, int)> partitioning_method,
        int number_of_partitions) :
        task_(task), mpi_interface_(mpi_interface), begin_(begin), end_(end), partition_(partitioning_method), number_of_partitions_(number_of_partitions)
    {
    }

    void run()
    {
        auto rank = mpi_interface_.MpiCommRank(MPI_COMM_WORLD);

        std::vector<unsigned int> partitioned_begin_end_values(2);
        if (rank == 0)
            partitioned_begin_end_values = partition();

        std::vector<unsigned int> slave_values(2);
        MPI_Scatter(&partitioned_begin_end_values[0], 2, MPI_UINT32_T, &slave_values[0], 2, MPI_UINT32_T, 0, MPI_COMM_WORLD);

        TaskType slave_task(task_);
        slave_task.map(slave_values[0], slave_values[1]);
        auto result = slave_task.reduce(0);

        std::vector<unsigned int> slave_results(number_of_partitions_);
        MPI_Gather(&result, 1, MPI_UINT32_T, &slave_results[0], 1, MPI_UINT32_T, 0, MPI_COMM_WORLD);

        if (rank == 0)
            for (auto slave_result : slave_results)
                task_.reduce(slave_result);
    }

private:
    TaskType& task_;
    const MpiAdapterInterface& mpi_interface_;
    int begin_;
    int end_;
    std::function<std::vector<std::pair<unsigned int, unsigned int>>(unsigned int, unsigned int, int)> partition_;
    int number_of_partitions_;

    std::vector<unsigned int> partition()
    {
        std::vector<unsigned int> iterator_values(number_of_partitions_ * 2);

        auto partitions = partition_(begin_, end_, number_of_partitions_);
        for (size_t i = 0; i < partitions.size(); ++i)
        {
            iterator_values[i * 2] = partitions[i].first;
            iterator_values[i * 2 + 1] = partitions[i].second;
        }

        return iterator_values;
    }
};

#endif // __MPI_PARALLEL_TASK_SCATTER_GATHER_H