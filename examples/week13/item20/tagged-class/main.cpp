#include <iostream>
#include "Figure.h"

int main () 
{
  Figure r {4, 7};
  std::cout << "Rectangle Area: " << r.area() << std::endl;
  Figure c {1};
  std::cout << "Circle Area: " << c.area() << std::endl;
  return 0;
}


