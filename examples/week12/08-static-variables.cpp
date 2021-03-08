#include <iostream>

// be careful with statics inside classes
// they are stored GLOBALLY - just as any other static
struct Foo {
  int value() {
    static int x;  // globals are initialized by default
    return ++x;
  }
};

int main () {
  Foo a, b;    // a pair of Foo objects - ordinarily unrelated...

  for (int i=0; i<10; ++i) {
    std::cout << "Value of a: " << a.value() << '\n';
    std::cout << "Value of b: " << b.value() << '\n';
  }
  return 0;
}

