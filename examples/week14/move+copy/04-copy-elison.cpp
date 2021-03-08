#include <stdio.h>

// what is the output of this program?
//
//
// see: http://en.cppreference.com/w/cpp/language/copy_elision

struct X {
  X()         { puts("default"); }
  X(const X&) { puts("copied"); }
  ~X()        { puts("deleted"); }
};

X foo() {
  return X();
}

int main() {
  foo();
}


// One would expect the copy contructor to be called in the return from foo()
// but that is not typically the case.
//
// The C++ standard says:
// "Note: A copy or move operation associated with a return statement may be elided"
//
// In other words:
// The implementation is free to skip the copy constructor. 
// This is the default behavior on buffy.

// although implemented as a return value optimization, copy elision can
// result in implementation defined behavior
//
// If compiled with -fno-elide-constructors 
// then the output would be:
//   default
//   copied
//   deleted
//   deleted


