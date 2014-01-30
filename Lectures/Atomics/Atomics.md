Atomics Lecture Notes
=====================
Slide 4
-------
* Both mutexes and atomics can be used to avoid this problem.
* Both will cause all caches and memories to be updated.

Slide 8
-------
* It is important to understand the relationship between mutexes and atomics. A mutex is like a knife, while an atomic is like a scapel.
* A mutex is usually an OS-level concept, an atomics is a CPU-level concept.

Slide 10
--------
* Atmoics depend upon assembly level compiler instructions.
* Some CPU architectures don't have these instructions.

Slide 11
--------
* The synchronizes-with relationship works across all processors and caches.

Slide 12
--------
* Look at the OrderingRelationships.sln example.
* It is possible, though unlikely, for the `while (!data_ready)` loop to continue forever.
