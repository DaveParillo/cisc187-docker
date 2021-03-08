#include <stdio.h>

class A {
  public:
    A() { putchar('A'); }
    A(const A &) { putchar('a'); }
};

class B: virtual A {
  public:
    B() { putchar('B'); }
    B(const B &) { putchar('b'); }
};

class C: virtual A {
  public:
    C() { putchar('C'); }
    C(const C &) { putchar('c'); }
};

class D:C,B {
  public:
    D() { putchar('D'); }
    D(const D &) { putchar('d'); }
};

int main() {
  D d1;
  D d2(d1);
}

