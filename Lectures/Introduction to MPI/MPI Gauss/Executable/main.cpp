#include <iostream>
#include <mpi.h>
#include "../Library/mpi_parallel_task.h"
#include "../Library/mpi_adapter.h"
#include "../Library/even_partitioning_of_consecutive_integers.h"
#include "../Library/gauss_task.h"

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int number_of_processes;
    MPI_Comm_size(MPI_COMM_WORLD, &number_of_processes);

    gauss_task task;
    MpiAdapter mpi;
    auto runner = MpiParallelTask<gauss_task>(task, mpi, 0, 100, even_partitioning_of_consecutive_integers, number_of_processes);

    runner.start();
    runner.complete();

    if (mpi.MpiCommRank(MPI_COMM_WORLD) == 0)
        std::cout << "The sum is " << task.get_sum() << std::endl;

    MPI_Finalize();
}