#include <iostream>

// from the week 2 slides warning about #define
//
// The behavior of this program changes depending on
// the way the arguments and and b are passed to the macro
//
// In this example,
// the number of times a is incremented even depends on the value of a!
//

// call function f with the larger of either a or b
//
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

using std::cout;

int f(const int x);

int main() {
  auto a = -5;
  const int b = 0;

  cout << "CALL_WITH_MAX(++a, b),    a = \t";
  for (int i = 1; i < 11; ++i) {
    CALL_WITH_MAX(++a, b);        // call f, but throw away the result
    cout << a << ' ';             // a should be one larger each iteration
  }

  a = -5;
  cout << "\nCALL_WITH_MAX(++a, b+10), a = \t";
  for (int i = 1; i < 11; ++i) {
    CALL_WITH_MAX(++a, b+10);
    cout << a << ' ';
  }

  return 0;
}

int f(const int x) {
  return x;
}
