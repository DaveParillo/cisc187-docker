#include <iostream>

class NotConstCorrect {
  int value_ = 0;
  public:
  void value( const int value ) { value_ = value; }
  int value() { return value_; }
};

class ConstCorrect {
  int value_ = 0;
  public:
  void value( const int value ) { value_ = value; }
  int value() const { return value_; }
};


int main () {
  int i = 13;
  NotConstCorrect ok;
  ok.value(i);
  std::cout << ok.value() << '\n';

  const NotConstCorrect const_ok = ok;
  // const objects cannot call non-const functions
  // your 'const' object could change!!
  //std::cout << const_ok.value() << '\n';  // will not compile

  i = 21;
  ConstCorrect c;
  c.value(i);
  std::cout << c.value() << '\n';

  const ConstCorrect const_c = c;
  std::cout << const_c.value() << '\n';
  // you can't do this with a const object either:
  // const_c.value(i);
  return 0;
}
