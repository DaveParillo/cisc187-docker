#include <stdio.h>

// from http://cppquiz.org/quiz/question/5

// What is the output of this program?
//
// Try to figure it out before compiling

struct A {
  A() { putchar('A'); }
};
struct B {
  B() { putchar('B'); }
};

class C {
  public:
    C() : a(), b() {}

  private:
    A a;
    B b;
};

int main() {
  C();
}

