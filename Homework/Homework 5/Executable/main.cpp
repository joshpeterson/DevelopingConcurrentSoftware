#include <iostream>
#include <mpi.h>
#include "../Library/mpi_parallel_task.h"
#include "../Library/mpi_adapter.h"
#include "../Library/even_partitioning_of_consecutive_integers.h"
#include "../Library/mpi_word_counter.h"

extern std::vector<std::string> gettysburg_address;

void verify_word_count(const std::string&, int, int);

int main(int argc, char* argv[])
{
    MPI_Init(&argc, &argv);

    int number_of_processes;
    MPI_Comm_size(MPI_COMM_WORLD, &number_of_processes);

    verify_word_count("earth", 1, number_of_processes);
    verify_word_count("four", 1, number_of_processes);
    verify_word_count("is", 3, number_of_processes);
    verify_word_count("it", 5, number_of_processes);
    verify_word_count("we", 10, number_of_processes);

    MPI_Finalize();
}

void verify_word_count(const std::string& word, int expected_count, int number_of_processes)
{
    mpi_word_counter task(word);
    MpiAdapter mpi;
    auto runner = MpiParallelTask<mpi_word_counter>(task, mpi, 0, gettysburg_address.size()-1, even_partitioning_of_consecutive_integers, number_of_processes);

    runner.start();
    runner.complete();

    if (mpi.MpiCommRank(MPI_COMM_WORLD) == 0)
    {
        if (task.get_count() == expected_count)
            std::cout << "Correct - found \"" << word << "\" " << expected_count << " times\n";
        else
            std::cout << "Incorrect - looking for \"" << word << "\" expected: " << expected_count << " actual: " << task.get_count() << std::endl;
    }
}