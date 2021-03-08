#include "Animal.h"

#include <iostream>

//
// The simple case of slicing involves copying a 
// derived object to a base type.
//

using std::cout;

int main () {
  Animal a = {"Alice"};
  Wolf w = {"Walt"};

  cout << "\nAssign wolf to a new Animal\n";
  Animal b = w;
  cout << "\n'b' name, expected 'Bob', actual is: " << b.name() << ".\n";

  call_v(b);
  call_cr(b);
  call_r(b);
  call_p(&b);

}

