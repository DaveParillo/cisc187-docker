#include <iostream>

int main() {
  char c   = 'a';
  bool b   = true;
  short s  = 997;
  int i    = 997;
  float f  = .333;
  double d = .333;

  std::cout << "Sizes: (bytes)\n";
  std::cout << "char:\t"   << sizeof(c) << "\n";
  std::cout << "bool:\t"   << sizeof(b) << "\n";
  std::cout << "short:\t"  << sizeof(s) << "\n";
  std::cout << "int:\t"    << sizeof(i) << "\n";
  std::cout << "float:\t"  << sizeof(f) << "\n";
  std::cout << "double:\t" << sizeof(d) << "\n";

  return 0;
}

