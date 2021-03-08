#include <iostream>
using std::cout;

class Foo {
  int value_ = 0;
  public:
    Foo (){}
    Foo (int x) : value_(x) {}
    int value () const { return value_; }
    int value (int x) { return value_ = x; }
    Foo& operator++ ();
    Foo operator++ (int);
    Foo& operator-- ();
    Foo operator-- (int);
};


Foo& Foo::operator++ () {
  cout << "pre-incrementing\t";
  value_ += 1;
  return *this;
}

Foo Foo::operator++ (int) {
  cout << "post-incrementing\t";
  Foo tmp(*this);  // or Foo tmp = *this;
  operator++();    // sometimes you see: ++(*this);
  return tmp;
}

Foo& Foo::operator-- () {
  cout << "pre-decrementing\t";
  value_ -= 1;
  return *this;
}

Foo Foo::operator-- (int) {
  cout << "post-decrementing\t";
  Foo tmp = *this;
  operator--();    // sometimes you see: --(*this);
  return tmp;
}


int main()
{
  Foo n(13);
  cout << "n is " << (++n).value() << '\n';
  cout << "n is " << (n++).value() << '\n';
  cout << "n is " << (--n).value() << '\n';
  cout << "n is " << (n--).value() << '\n';
  cout << "n is " << n.value() << '\n';
  ++n;
  ++n;
  cout << "n is " << n.value() << '\n';
  return 0;
}
