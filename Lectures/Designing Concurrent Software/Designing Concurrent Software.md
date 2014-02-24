Designing Concurrent Software Lecture Notes
===========================================
Slide 4
-------
* This is the example from the Asynchronous operations lecture.

Slide 13
--------
* This is where the engineering comes into play. We need to optimize, to make the best decision based on the constraints.

Slide 21
--------
* Mutexes are often the memory read from and written to cache. They can cause the ping-ponging.
* The programming languages we use hide cache from us, and rightfully so. We need to use profilers to measure it.
