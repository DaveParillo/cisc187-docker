# Prefer class hierarchies to tagged classes

## Item 20

The examples in this directory are a C++ port of an example in
Effective Java

From Effective Java by Joshua Bloch (Addison-Wesley). 
Copyright 2008 Joshua Bloch, 978-0-321-35668-0.

The main idea is that a "tagged class" - using some class member as a flag, or tag 
you use to change class behavior based on its value is a REALLY BAD IDEA.

It's an anti-pattern: that is, an example of what NOT to do.

The alternative to a 'tagged class' is a real class hierarchy.


