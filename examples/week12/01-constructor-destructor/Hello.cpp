#include "Hello.h"
#include <iostream>
#include <string>


Hello::Hello () : name_ {"Alice"} { 
  std::cout << "make a default hello\n";
}

Hello::Hello (std::string n) { 
  name_ = n; 
  std::cout << "make a '" << n << "' hello\n";
}

Hello::~Hello () { 
  std::cout << "destroy the '" << name_ << "' hello\n";
}


