//
// Side effects:
// A function that modifies its parameters 
// is said to have 'side-effects'.
//
// Programs with too many side-effects are hard to predict and debug.
//
// Given that the names of these function provide no insight to their purpose,
// there is no way to know without inspecting the source if
// pi is modified when provided.
//
#include "side-effects.h"
#include <iostream>

int main()
{
  double pi = 3.14159;
  std::cout << "in main.\npi = " << pi << '\n';
  dig(pi);

  std::cout << "Returned to main.\npi = " << pi << '\n';
  return 0;
}


void dig(double& val)
{
  std::cout << "Digging...\n";
  val *= 2;
  deeper(val);
  std::cout << "Done digging...\n";
}

void deeper(double& val)
{
  val -= 1;
  std::cout << "now even deeper....\n";
}

