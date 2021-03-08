#include <cstdio>
#include <string>

// mostly taken from http://stackoverflow.com/a/25453490

// Base class
struct A {
  int a = 13;
  std::string words = "struct A words";
  A() {}
  A(const A& other) {
    puts("'A' copy constructor");
  }
  virtual void run() const { puts("I am an 'A'"); }
};

// Derived class
struct B: public A {
  int b = 5;
  double x = 21.0;
  B():A() {}
  B(const B& other):A(other) {
    puts("'B' copy constructor");
  }
  virtual void run() const { puts("I am a 'B'"); }
};

void g(const A & a) {
  a.run();
}

void h(const A a) {
  a.run();
}

int main() {
  puts("Call by reference");
  g(B());
  puts("Call by copy (slice B)");
  h(B());


  // more insidious slicing
  B b1;
  B b2;
  b1.a = 3;
  b1.b = 7;
  b1.words = "it was the best of times";
  b2.a = 42;
  b2.b = 8;
  b2.x = 34.5;
  b2.words = "or maybe the worst of times?";
  printf("b1: %s, %.2f, %d, %d\n", b1.words.c_str(), b1.x, b1.b, b1.a);
  printf("b2: %s, %.2f, %d, %d\n", b2.words.c_str(), b2.x, b2.b, b2.a);

  puts("copy b2 to an a ref and copy b1 to same ref");
  A& a_ref = b2;
  a_ref = b1;

  printf("b1: %s, %.2f, %d, %d\n", b1.words.c_str(), b1.x, b1.b, b1.a);
  printf("b2: %s, %.2f, %d, %d\n", b2.words.c_str(), b2.x, b2.b, b2.a);

}

