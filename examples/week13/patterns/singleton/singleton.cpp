#include <iostream>

// This is the 'classic' singleton pattern.
// Frequently implemented before C++03
// Issues:
//  - Not thread safe
//  - Imprecise pointer ownership
//

// Declaration
class Singleton {
  public: 
    int value() {return value_;}
    void value(int value) { value_ = value;}

    static Singleton* instance();
  private:
    int value_;
    Singleton() : value_{0} {}
    static Singleton* instance_;
};

// Implementation 
Singleton* Singleton::instance_ = nullptr;

Singleton* Singleton::instance() {
  if (instance_ == nullptr) {
    instance_ = new Singleton;
  }
  return instance_;
}

int main() {
  Singleton* s = Singleton::instance();
  std::cout << "s: " << s->value() << '\n';

  Singleton* x = Singleton::instance();
  x->value(3);
  std::cout << "s: " << s->value() << '\n';
  std::cout << "x: " << x->value() << '\n';
  Singleton* y = Singleton::instance();
  y->value(5);
  std::cout << "s: " << s->value() << '\n';
  std::cout << "x: " << x->value() << '\n';
  std::cout << "y: " << y->value() << '\n';

  std::cout << "addresses: " << '\n';
  std::cout << "s: " << &s << '\t';
  std::cout << "x: " << &x << '\t';
  std::cout << "y: " << &y << '\n';
  std::cout << "instances: " << '\n';
  std::cout << "s: " << &(*s) << '\t';
  std::cout << "x: " << &(*x) << '\t';
  std::cout << "y: " << &(*y) << '\n';
}

