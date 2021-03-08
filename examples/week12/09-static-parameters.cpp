#include <stdio.h>

class A {
public:
  A() { puts("a"); }
  ~A() { puts("A"); }
};

class B {
public:
  B() { puts("b"); }
  ~B() { puts("B"); }
};

class C {
public:
  C() { puts("c"); }
  ~C() { puts("C"); }
};

A a;                        // what is the lifetime of a?

void foo() { static C c; }  // what is the lifetime of c?
int main() {
  B b;
  foo();
}

