#include <cassert>
#include <iostream>
#include "Color.h"
#include "ColorPoint.h"
#include "Point.h"

// This example adds a 'color' feature to a point using inheritance
//
// Not reccommended.
//
// This example is drawn from
// Effective Java - Pages 37 - 38
//
// Joshua Bloch does a good job explaining the problem
// and note that this is largely a problem related to object oriented programming in general
// It's not a "C++" or a "Java" problem.
//
// While one could argue that this is exactly what was indended,
// in the real world, it is almost always a bug.
//
int main ()
{
  Point      a {3, 4};
  ColorPoint b {3, 4, Color::RED};
  ColorPoint c {3, 4, Color::BLUE};

  assert (a == b);
  assert (b == a);
  assert (a == c);

  assert (b != c);  // ouch! a == b AND a == c, but b != c
  
  std::cout << "program complete.  all assertions in this program are true\n";
}


