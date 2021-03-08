#include "add-function.h"
#include "concepts.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main() {
  // both args need to be the same type
  cout << addSame(13, 21) << std::endl;
  cout << addSame(double(2), 3.14159) << std::endl;

  // any type that overloads operator+ will work
  cout << addSame(std::string("Hello, "), 
                  std::string("world!")) << std::endl;

  cout << addAny(2, 3.14159) << std::endl;
  return 0;
}



