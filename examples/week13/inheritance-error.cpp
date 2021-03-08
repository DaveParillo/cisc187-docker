#include <iostream>

struct A {
  virtual void foo (int a = 1) {
    std::cout << "A: " << a;
  }

  virtual ~A() = default;
};

// A virtual function call uses the default arguments 
// in the declaration of the virtual function determined 
// by the static type of the pointer or reference denoting the object. 
//
// An overriding function in a derived class does not acquire default 
// arguments from the function it overrides.
//
// read that last sentence again.
//
struct B : A {     // public A is redundant here (it's a struct)
  virtual void foo (int b = 2) {
    std::cout << "B: " << b;
  }
};

int main () {
  A *b = new B;
  b->foo();
  delete b;
}

