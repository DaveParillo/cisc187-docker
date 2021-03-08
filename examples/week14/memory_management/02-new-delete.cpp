#include <iostream>

class A {
  public:
    explicit A( int i = 0 );
    ~A();
    int a() { return a_; }
    int b() { return b_; }
    int c() { return c_; }
  private:
    int a_ = 0;
    int b_ = 0;
    int c_ = 0;
};

A::A( int i ) : a_(i), b_(i + 1), c_(i + 2) {
  std::cout << "A constructor called\n";
}

A::~A() {
  std::cout << "A destructor called\n";
}

int main() {
  A* a = new (std::nothrow) A;  // new may throw an exception
  if(a == nullptr) {            // but we can choose to check instead
    std::cout << "failed to allocate memory for an A\n";
    return 1;
  }
  std::cout << "a: " << a->a() << a->b() << a->c() << '\n';
  delete a;
  return 0;
}
