#include <iostream>
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"

int main () 
{
  Rectangle r {4, 7};
  std::cout << "Rectangle Area: " << r.area() << std::endl;
  Square s {7};
  std::cout << "Square Area: " << s.area() << std::endl;
  Circle c {1};
  std::cout << "Circle Area: " << c.area() << std::endl;
  return 0;
}


