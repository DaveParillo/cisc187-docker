// from Effective C++, item # 35
//
// Does is make sense for a Square to inherit from Rectangle?
#include <cassert>
#include <iostream>
#include "Rectangle.h"
#include "Square.h"

// function to increase r's area
void makeBigger(Rectangle& r);

int main () 
{
  Rectangle rect;
  std::cout << "Rectangle Size: " << rect << std::endl;
  makeBigger(rect);
  std::cout << "  New: " << rect << std::endl;
  Square s;
  std::cout << "Square Size: " << s << std::endl;
  makeBigger(s);
  std::cout << "  New: " << s << std::endl;
  return 0;
}


void makeBigger(Rectangle& r)
{
  size_t oldHeight = r.height();
  r.width(r.width() + 10);
  assert(r.height() == oldHeight); // assert that r's height is unchanged
}


