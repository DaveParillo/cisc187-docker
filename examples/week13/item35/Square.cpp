// from Effective C++, item # 35
//
#include "Square.h"
#include <cstddef>
#include <iostream>

using std::size_t;

void Square::height(size_t new_height) { 
  _ht = new_height;
  _wd = _ht;
}

void   Square::width (size_t new_width)  { 
  _wd = new_width;
  _ht = _wd;
}

size_t Square::height() const { 
  return _ht;
}

size_t Square::width () const { 
  return _wd;
}

std::ostream& operator<<(std::ostream& os, const Square& s)
{
  return os << s.height() << " h, " << s.width() << " w\n";
}

