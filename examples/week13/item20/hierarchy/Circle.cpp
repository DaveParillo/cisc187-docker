#include "Circle.h"

double Circle::area() const 
{ 
  return pi *  _radius * _radius; 
}

std::ostream& operator<<(std::ostream& os, const Circle& rhs)
{
  return os << rhs.radius();
}



