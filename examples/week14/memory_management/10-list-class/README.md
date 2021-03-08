
An alternative List implementation
==================================

The Link class demonstrated in section 17.9 and 17.10
is a prime example of how **not** to implement a linked
list of your own.

It succeeds at demonstrating some pointer problems,
but only the problems.
It provides no solutions.
Do **not** emulate that in your own projects or code.

(Your future co-workers will thank you)

This directory contains an extremly minimal linked list.

It attempts to demonstrate the basic ideas of pointer ownership
discussed in class.

The List class *owns* its own pointers and manages its own memory.
Users of a List do not care about any of the implementation details.


