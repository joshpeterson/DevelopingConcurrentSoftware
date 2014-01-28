Threads Lecture Notes
=====================
Slide 3
-------
* Interprocess communication may be via file, a network connection (even on the same machine), special shared memory, or other ways.
* A thread is a unit of execution. You can think if it is as a sequence of instructions the CPU executes.
* This is an interview question that we ask.

Slide 4
-------
* Task parallelism is often a pipeline
* Data parallelism is the goal - scalability allows us to solve the same problem faster in the future - the free lunch

Slide 6
-------
* Near the end of the course we will briefly discuss concurrency with multiple processes.

Slide 9
-------
* The example is the code in the CallableTypes directory

Slide 10
--------
* Think about what this code depends upon.
* Can we externalize that dependency?

Slide 11
--------
* We'll see the testable code later.

Slide 14
--------
* Remember that the name of an array is really a pointer.
* The arugment is not converted _before_ it is passed to the `std::thread` constructor. It is converted later, on the new thread of execution before the callable thing is called.
* The `oops` method may exit before the argument is converted.
* How can we correct this problem?

Slide 15
--------
* Use an explicit conversion so that we tell the compiler when to create the `std::string`.
* Recall what we mentioned earlier - the computer is doing exactly what we tell it to, but no more. We need to be explicit with our needs.

Slide 16
--------
* Recall that a reference is a pointer that cannot be set to NULL. It has the same lifetime management concerns.

Slide 24
--------
* Note that the `guard` class instance does not own the `std::thread` object. It holds a reference to it.
* The `guard` class is not responsible for the desctruction of the `std::thread` object.

Slide 26
--------
* Sometimes it helps to make a table to understand what is occuring in cases like this.
* Now that we can transfer ownership, we can improve the thread RAII class.

Slide 27
--------
* Now we move the `std::thread` argument and take ownership.
* Now `guard` checks that the `std::thread` is joinable in its constructor, since the `gaurd` owns it, it assumes no one else will call `join`.

Slide 28
--------
* Notice that the `std::thread` no longer has a name, so the calling code cannot join or detach it.
* The transfer of ownership via `std::move` allows this.
* Notice the syntax for the call to the `std::thread` constructor.
* There is a bug in the Williams book on page 27 - this is the "most vexing parse".
