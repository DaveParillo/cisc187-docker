#include <cassert>
#include <iostream>
#include "Color.h"
#include "ColorPoint.h"
#include "Point.h"

// This example correctly adds a 'color' feature to a point using composition
//
// It's still very minimal.
// 
// This example is a C++ port of the example in 
// Effective Java - Pages 37 - 38

int main ()
{
  Point p {3,4};
  ColorPoint cp {p, Color::RED};
  ColorPoint cp2 {p, Color::BLUE};

  assert (p == cp.as_point());
  assert (cp != cp2);
  
}
