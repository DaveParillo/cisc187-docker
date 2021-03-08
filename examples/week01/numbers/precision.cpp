#include <iostream>

int main() {
  float x = 1.0/999;
  float sum = 0;
  for (int i=0; i<999; ++i) {
    sum+=x;
  }

  std::cout << "Sum 1/999, 999 times:\n";
  std::cout << sum << "\n";

  short y = 40000;
  int i = 1000000;
  std::cout << "show 40,000 (as a short), 1 million squared:\n";
  std::cout << y << ",\t" << i*i << "\n";
  return 0;
}

