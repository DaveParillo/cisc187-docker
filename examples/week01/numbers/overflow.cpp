#include <iostream>

int main() {
  // signed 8 bit int
  int8_t x = 128;
  int8_t y = 1;

  std::cout << "x + y = " << (x + y) << '\n';

  // unsigned 8 bit int
  uint8_t a = 255;
  uint8_t b = 1;
  uint8_t c = a + b;
  std::cout << "a + b = '" << c << "'\n";
}

