#include "Animal.h"

#include <iostream>
#include <vector>

//
//  filling a vector ends up creating copies again
//

int main () {
  std::vector<Animal> v {
    Animal{"alice"},
    Canine{"chuck"},
    Wolf{"walt"},
  };

// uncomment if you don't believe these all display the same thing
/*
  cout << "Calling pass by value\n";
  for (auto i = 0u; i < v.size(); ++i) {
    call_v (v[i]);
  }
  cout << "\nCalling pass by const reference\n";
  for (auto i = 0u; i < v.size(); ++i) {
    call_cr (v[i]);
  }
*/
  std::cout << "\nCalling pass non-owning pointer\n";
  for (auto i = 0u; i < v.size(); ++i) {
    call_p (&v[i]);
  }

}

