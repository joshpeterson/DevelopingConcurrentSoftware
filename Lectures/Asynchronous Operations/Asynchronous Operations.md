Asynchronous Operations Lecture Notes
=====================================
Slide 2
-------
* In this lecture we'll learn how to communicate between two asychronous operations.
* As we mentioned in the last lecture, we want the minimum synchronization necessary.

Slide 3
-------
* A `std::condition_variable`, like a `std::mutex` is a synchronization tool.
* It works with a `std:mutex` to facilitate communication between operations on two threads.
* Note that all languages have these tools, they are just spelled differently.

Slide 4
-------
* Unlike our producer/consumer queue, `std::queue` is not internally thread-safe.
* None of the standard containers are internally thread-safe. They must be protected by the client code using them.
* Four important things happen in the `wait` method.

Slide 5
-------
* The call to `notify_one` _signals_ the condition variable.
* It allows one thread to exit the `wait` method.
* Note that multiple threads may be waiting on the same condition variable.
* Why can't we use a `bool` here? That would be simpler.

Slide 8
-------
* A _predicate_ is a method which returns a `bool`.
* Note the lambda expression. We can pass any callable object to the `wait` method.
* We need to check the Boolean condition again, after `wait` returns, because we could get a spurious wakeup. More on this later.
* Ensure that the predicate does not have any side effects.

Slide 12
--------
* Often you want to be in control of which threads are running.
* Some threading libraries require you to explicitly join all threads, or the application will hang when it is shutdown.

Slide 13
--------
* Note that `std::async` may or may not create a new thread. By default, the implementation decides, although we can tell it what to do.
* Let's see an example.

Slide 17
--------
* Note that I did not mention the use of `std::condition_variable` to signal a thread to exit as a guideline.
  * It is a good practice.
  * There is a better way to do this, which we will learn later.
* Ending a background thread safely is is another common pattern in concurrent code.
