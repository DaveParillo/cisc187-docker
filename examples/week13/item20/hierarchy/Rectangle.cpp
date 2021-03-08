#include "Rectangle.h"

#include <iostream>

double Rectangle::area() const
{ 
  return _ht * _wd; 
}


std::ostream& operator<<(std::ostream& os, const Rectangle& r)
{
  return os << r.height() << " h, " << r.width() << " w";
}


