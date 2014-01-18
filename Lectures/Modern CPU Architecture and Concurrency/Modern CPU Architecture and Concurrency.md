Modern CPU Architecture and Concurrency Lecture Notes
=====================================================

Slide 2
-------
* This is the common Moore's Law graph.
* Notice how transistor counts are continuing to increase linearly (at least until 2011).
* We're still seeing the same increase, but this does not mean that processors are getting faster.
* We have a looming challenge, which is nothing new.

Slide 3
-------
* Thirty years ago new hardware was on the horizon.

Slide 4
-------
* We had many different solutions, many different architectures.

Slide 5
-------
* Has anyone heard of Beowulf?
* COTS machines, well-known languages won.
* But something is happening (the end of Dennard Scaling) which means we are seeing another change.

Slide 6
-------
* Problems continue to get larger, we need faster computers to handle them.
* As in the past, we're seeing many different approaches.
* We're unsure which solutions will win.

Slide 7
-------
* As engineers, we often think of a computer using the Von Neumann model.
* Although useful for demonstration, this model is wrong.

Slide 8
-------
* The architecture of real hardware is much more complex.
* This is the Xeon Phi architecture. Phi is a new acelerater from Intel, which we will discuss later.

Slide 9
-------
* Engineers optimize.
* As programmers, our goal is to optimize the hardware we have available.
* We need to understand the hardware and learn to optimize it.
* Hint: We are getting more processors, not faster processors.

Slide 10
--------
* This is an old slide, but it shows when the trend started.
* Herbe Sutter saw this trend many years ago.
* The green line is Moore's Law (number of transistors).
* Look at clock speed - it is approaching an asymtote.
* Where are all of the transistors going then? - They are going into more processors.
* Why is this happenning? - We will find out a bit later.

Slide 11
--------
* The hardware jungle is Herb Sutter's new answer to this trend.
* Complex processors with a unified memory model mean more transistors per processor. This is the Von Neumann architecture, so some degree.
* These architectures support serial exection, and usually provide less performance per watt.
* As processors become simpler and more specialized and memory become more disjoint, we get better performance per watt, at the cost of more parallel (and more complex) code.
* With clock speed increase slowing down performance per watt becomes the measuring stick.
    * In mobile devices, power matters on a small scale.
    * In a cluster (see the Beowulf cluster earlier) power matters on a large scale.
* What does this mean? - To succeed software must be written with concurrency designed in. Serial code will not get faster as better hardware is provided, like it did in the past.

Slide 12
--------
* As developers, we can do this using the same principles we learned about good software development practices.
* Our tools will change though, so we must learn about them.

Slide 13
--------
* We also need to consider that our code will be mearsure differently.
* How will we handle algorithms that are necessarily serial? Can these bottlenecks be prevented with new hardware?

Slide 14
--------
* We can also see the shift in hardware represented in lagnuage evolution.
* Even ten years ago, languages were optimized for developer efficiency.
* Those languages are still useful for many problems.
* Scale matters
    * PHP is useful for web development on a small scale.
    * Facebook has written a PHP-to-C++ compiler!
    * Sometimes these languages scale unexpectedly - Twitter uses Ruby on a large scale.
* Parallel architectures mean languages closer to the hardware, which are not optimized for developer productivity.
* Functional languages may be making a return, since memory is plentiful.

Slide 15
--------
* We are living in an exciting time for computers, hardware, and software development.
* We must be prepared to exceed in a new environment.
