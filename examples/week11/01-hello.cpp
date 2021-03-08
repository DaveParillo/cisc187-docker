#include <cstdio>

// Declare a class and define function inside the class
// In C++, a class is merely a struct with private default access
struct Talk {
    void hello() {
      std::puts("Hello, world!");
    }

};  // semi-colon required at end of declatation

int main() {
  Talk say;        // Create an object from a class
  say.hello();     // Call a function in the object
  return 0;
}


