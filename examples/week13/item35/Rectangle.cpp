// from Effective C++, item # 35
#include "Rectangle.h"
#include <iostream>

using std::size_t;

void Rectangle::height(size_t new_height) { 
  _ht = new_height;
}

void Rectangle::width (size_t new_width)  { 
  _wd = new_width;
}

size_t Rectangle::height() const { 
  return _ht;
}

size_t Rectangle::width () const { 
  return _wd;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& r)
{
  return os << r.height() << " h, " << r.width() << " w\n";
}

