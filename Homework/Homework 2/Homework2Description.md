Homework 2
==========
This homework assignment requires you to write a vector with a limited interface that is safe to call from multiple threads.

//wrap a standard vector
//provide own methods
//look at producer/consumer test

Due: Prior to class on February 3

Starting with the initial source code in Homework2.sln:

1. Implement the `push_back` method.
2. Implement the `at` method.
3. Implement the `size` method.
3. Use test driven design to write the code.
4. Ensure that both methods may be called from multiple threads.

You will be graded on:

1. The correctness of the thread-safe vector implementation as measured by the validations in the `main` function.
2. The organization and content of the vector implementation and the unit test code.

This assignment is intended to be collaborative. You may work on it with one or two other students in the course, and provide one implementation for the group. You are also encouraged to submit your finished work prior to the due date and receive feedback from me.

You should submit your finished work as a pull request on Github.

Note: You may find the new C++11 use of the keyword `using` handy for this homework. See [this](http://stackoverflow.com/questions/2795023/c-template-typedef) question on StackOverflow for details.
