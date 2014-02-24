#include <mpi.h>
#include <iostream>

int main(int argc, char* argv[]) ///Command-line arguments are required despite not being used
{
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0) //by convention, rank 0 is master process. 
    {
        int value = 17;
        int result = MPI_Send(&value, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);//world is communication
		//n-1 = 1 partitions (since 0 counts...)
        if (result == MPI_SUCCESS)
            std::cout << "Hello, world from rank 0!" << std::endl;
    }
    else if (rank == 1)
    {
        int value;
        int result = MPI_Recv(&value, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
            MPI_STATUS_IGNORE);
        if (result == MPI_SUCCESS && value == 17)
            std::cout << "Hello, world from rank 1!" << std::endl;
    }
    MPI_Finalize();
    return 0;
}