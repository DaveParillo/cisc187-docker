//
// From the overload and template tutorial at
// http://www.cplusplus.com/doc/tutorial/functions2/
//
// Modified to include concepts

#include <iostream>
#include "concepts.h"

// comparable is just defined as:
// #define Comparable typename
// The use of 'COmaprable' here is a way to make it clear
// what KIND of typename or class is expected
// see concepts.h
//
// 'Concepts' and 'requires' won't exist until C++17 or 20
// For now, some people (mostly Stepanov) do this.
// 

template <Comparable T, Comparable U>
bool are_equal (T a, U b) {
  return (a==b);
}

int main () {
  if (are_equal(10,10.0)) {
    std::cout << "x and y are equal\n";
  } else {
    std::cout << "x and y are not equal\n";
  }
}


