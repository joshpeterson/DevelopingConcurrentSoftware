Homework 5
==========
Use the `MpiParallelTask` class from the MPI lecture to write a distributed parallel program that will count the number of occurrences of a given word in a list of words.

Due: Prior to class on February 24

Starting with the initial source code in Homework5.sln:

1. Implement the methods of the `mpi_word_counter` class.
2. Count the number of times the `word_to_find` constructor argument occurs (do a case-insensitive match).
3. The `get_count` method should return this count.

You will be graded on:

1. The correctness of the `mpi_word_counter` implementation as measured by the validations in the `main` function.
2. The organization and content of the `mpi_word_counter` implementation and the unit test code.
3. The execution of your program with 4 MPI processes, using the command line `mpiexec -n 4 Executable.exe`.

You should be able to reuse much of the code from Homework 3. You will need to make a few modifications to the code from Homework 3 though.

This assignment is intended to be collaborative. You may work on it with one or two other students in the course, and provide one implementation for the group. You are also encouraged to submit your finished work prior to the due date and receive feedback from me.

You should submit your finished work as a pull request on Github.

