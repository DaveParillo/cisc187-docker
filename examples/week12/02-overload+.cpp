#include <iostream>

class Foo {
  int f_;   // unlike struct, default access is private
  public:
  Foo ( const int& init ) 
    : f_(init) {}
  const int& value() const {
    return f_;
  }
};

// prefer keeping functions out of classes unless absolutely required
int operator+ (const Foo& lhs, const Foo& rhs ) {
  return lhs.value() + rhs.value();
}

int main () {
  Foo x = {8};
  Foo y = {13};
  std::cout << "x + y = " << x + y;
  return 0;
}
