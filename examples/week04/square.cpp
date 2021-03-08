#include "square.h"
#include <iostream>

int main()
{
  std::cout << square(4) << std::endl;
  std::cout << square(3.14159) << std::endl;
  return 0;
}

int square(const int x){
  return x * x;
}

double square(const double x){
  return x * x;
}

