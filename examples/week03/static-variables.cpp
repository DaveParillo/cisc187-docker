#include <iostream>

int func() {
  static int x = 0;
  static int y = 1;
  x = y;
  y += x;
  return x;
}

int main() {
  std::cout << "Number sequence:\n:\t";
  for (int i = 0; i < 8; ++i) {
    std::cout << func() << ' ';
  }
  std::cout << '\n';
  return 0;
}

