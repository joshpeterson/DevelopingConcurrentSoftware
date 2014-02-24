#ifndef __MPI_PARALLEL_TASK_H
#define __MPI_PARALLEL_TASK_H

#include <functional>
#include <utility>
#include <vector>

#include "mpi_adapter_interface.h"

template <typename TaskType>
class MpiParallelTask
{
public:
    MpiParallelTask(TaskType& task, const MpiAdapterInterface& mpi_interface, unsigned int begin, unsigned int end,
        std::function<std::vector<std::pair<unsigned int, unsigned int>>(unsigned int, unsigned int, int)> partitioning_method,
        int number_of_partitions) :
        task_(task), mpi_interface_(mpi_interface), begin_(begin), end_(end), partition_(partitioning_method), number_of_partitions_(number_of_partitions)
    {
    }

    void start()
    {
        auto rank = mpi_interface_.MpiCommRank(MPI_COMM_WORLD);

        if (rank == 0)
        {
            std::vector<unsigned int> iterator_values(2);
            auto partitions = partition_(begin_, end_, number_of_partitions_);
            for (size_t i = 1; i < partitions.size(); ++i)
            {
                iterator_values[0] = partitions[i].first;
                iterator_values[1] = partitions[i].second;

                mpi_interface_.MpiSend(&iterator_values[0], 2, MPI_UINT32_T, i, 0, MPI_COMM_WORLD);
            }

            if (!partitions.empty())
                task_.map(partitions[0].first, partitions[0].second);
        }
        else
        {
            std::vector<unsigned int> iterator_values(2);
            MPI_Status status;
            mpi_interface_.MpiRecv(&iterator_values[0], 2, MPI_UINT32_T, 0, 0, MPI_COMM_WORLD, &status);

            TaskType slave_task(task_);
            slave_task.map(iterator_values[0], iterator_values[1]);

            auto result = slave_task.reduce(0);

            mpi_interface_.MpiSend(&result, 1, MPI_UINT32_T, 0, 0, MPI_COMM_WORLD);
        }
    }

    void complete()
    {
        auto rank = mpi_interface_.MpiCommRank(MPI_COMM_WORLD);

        if (rank == 0)
        {
            for (int slave_process_rank = 1; slave_process_rank < number_of_partitions_; ++slave_process_rank)
            {
                MPI_Status status;
                unsigned int output;
                mpi_interface_.MpiRecv(&output, 1, MPI_UINT32_T, slave_process_rank, 0, MPI_COMM_WORLD, &status);
                task_.reduce(output);
            }
        }
    }

private:
    TaskType& task_;
    const MpiAdapterInterface& mpi_interface_;
    int begin_;
    int end_;
    std::function<std::vector<std::pair<unsigned int, unsigned int>>(unsigned int, unsigned int, int)> partition_;
    int number_of_partitions_;
};

#endif // __MPI_PARALLEL_TASK_H