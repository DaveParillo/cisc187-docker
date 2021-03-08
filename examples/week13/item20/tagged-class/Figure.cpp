#include "Figure.h"

double Figure::area() const 
{ 
  switch (_shape) {
		case rectangle:
			return _ht * _wd;
    case circle:
      return pi *  _radius * _radius; 
  }
  return 0;  // is this a good idea??
}

std::ostream& operator<<(std::ostream& os, const Figure& rhs)
{
  switch (rhs.shape()) {
		case rectangle:
			os << rhs.height() << " h, " << rhs.height() << " w";
    case circle:
      os << rhs.radius(); 
  }

  return os;
}



