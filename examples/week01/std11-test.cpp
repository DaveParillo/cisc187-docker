// A simple test for modern C++ compiler
// you may need to compile with either
// make -std=c++11 std11-test
// or
// c++ -std=c++11 std11-test.cpp -o std11-test
//
#include <iostream>

int main() {
  int test[] = { 1, 2, 3, 5, 8 };  // can we use an initializer list?
  for (auto i: test) {             // can we use a range-for loop?
    std::cout << "i is " << i << '\n';
  }
  return 0;
}


