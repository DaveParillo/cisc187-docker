#include "Square.h"


double Square::area() const
{ 
  return rect.area();
}


std::ostream& operator<<(std::ostream& os, const Square& rhs)
{
  return os << rhs.side();
}


