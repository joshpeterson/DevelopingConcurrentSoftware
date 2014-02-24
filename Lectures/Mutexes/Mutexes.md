Mutexes Lecture Notes
=====================
Slide 3
-------
* Some languages define both benign and problematic race conditions.
* In C++ any race condition is considered problematic, called a data race.
* In C++ any data race is undefined behavior - and you don't want that.

Slide 4
-------
* The `shared` global variable is the shared data.
* One thread will read from that memory location.
* One thread will write to that memory location.
* What will be printed?
* There are actually two data races in this example. Can you find the other one?

Slide 5
-------
* Note that we don't always get the same answer - why?
* Think about what is still wrong with this code.

Slide 7
-------
* What is the expected value of the sum?
* Notice again that we see different behavior each run, but it is correct.
  * This is common for concurrent programs.
  * We allow the compiler and the OS freedom to allow certain segments of code to be unsynchronized.
  * We control where the synchronization happens.
  * We strive for the minimum synchronization necessary, because synchronization always serializes the code, and we want to avoid that.
* Note that here we are not calling the `enqueue` method from a thread while the `try_dequeue` method is being called, but we could, and most producer/consumer queues operate this way.
* We'll find that shared data between threads is not too difficult if you use some common patterns. The producer/consumer queue is one of them.
