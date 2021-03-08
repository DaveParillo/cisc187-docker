#include <iostream>

struct Fibonacci {
  uint16_t f5;
  uint16_t f6;
  uint16_t f7;
};

int main() {
  // C++ will implicitly define a constructor if we don't write one
  Fibonacci foo = {5, 8, 13};
  std::cout << "The fifth, sixth and seventh fibonacci numbers are: " 
    << foo.f5 << ", "
    << foo.f6 << ", and "
    << foo.f7 << ".\n";


  // The -> operator is used to access members of a pointer to a class
  // it's a convenience to avoid operator precendence with * and .
  Fibonacci* bar = &foo;
  std::cout << "The fifth, sixth and seventh fibonacci numbers are (still): " 
    << bar->f5 << ", "
    << bar->f6 << ", and "
    << (*bar).f7 << ".\n ";   // same as ->

  return 0;
}


