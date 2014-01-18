Dennard Scaling Lecture Notes
=============================
Slide 2
-------
* We have already seen this slide today. Now we understand why it matters.
* If the number of transistors continues to increase (and it does) why are things different now?

Slide 5
-------
* Here V is the operating voltage, Tox is the oxide size, and L is the channel length.
* As transistors get smaller, they get faster and use less power.
* This is the free lunch for software developers.
* Dennard provided a roadmap for hardware engineers. If you can make transistors this small, this will be the result.
* Around 2005 something happened though - it became significantly more difficult to make transistors smaller.

Slide 6
-------
* Although we still had more transistors (Moore's law), they stopped getting faster, and they stopped using less power (Dennard scaling).
* So we are really seeing the end of Dennard scaling.
* How do we continue to end up with more transistors? Look at the bottom curve - more cores.
* Serial performance of the Von Neumann machine is not increasing, but the potential for performance of concurrent software has increased.
* Maybe the free lunch is not quite over yet.

Slide 7
-------
* Intel and others continue to scale down, but it is getting more difficult.
* The same techniques and materials won't provide any more benefit.
* Based on the power equation, you can see why Dennard scaling was so beneficial. As V<sub>DD</sub> decreased, power decreased by its square.
* For greater V<sub>DD</sub>, V<sub>DD</sub><sup>2</sup> trumped this equation. At lower V<sub>DD</sub>, V<sub>DD</sub><sup>2</sup> is much less important. So I<sub>LEAK</sub> begins to matter.
* Mobile devices have also made I<sub>LEAK</sub> more important. Imagine the impact of even a small leakage current on a phone.

Slide 8
-------
* Of course, hard design engineers are smart, they will continue to push the envelope.
* Intel has missed some targets for smaller manufacturing techniques.

Slide 9
-------
* We will continue to get different transistor designs.
* Thanks to abstraction, software engineers don't care too much - we only want on and off.
* Abstraction details will start to leak into the software though.

Slide 10
--------
* Suppose that we really need to optimize for power.
    * In a data center, power may be the greatest cost.
    * In a mobile device battery life may be the most important feature.
* Most processors now turn off or slow down when not needed.
* Imagine a transistor that has a lower V<sub>DD</sub> and is *less reliable*.
* Could we allow answers in some cases? Some people are exploring this option.
* Maybe we don't need general purpose processors for all applications. Can use specific details of the problem to optimize for both power and performance?

Slide 11
--------
* To get the free lunch we *must* learn to write concurrent code.
* We have to gain an understanding of the hardware available.
    * What problem is it optimized to solve?
    * Should we run some code on faster, more expensive (power and otherwise) hardware?
    * Should we instead run the code on slower, cheaper hardware?
    * Will the user notice a difference?
* What roll will unreliable results play?
    * Will compilers handle this?
    * Will we need to write software assuming the results may be wrong?
    * We will not address this issue, it is speculative at this point, but we should be aware of it.
