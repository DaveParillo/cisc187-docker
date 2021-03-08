#define HELLO_CONSTRUCTOR

#include "Hello.h"
#include <iostream>


int main()
{
  Hello al;
  std::cout << "Hello, " << al.name() << "!\n";

  Hello me;
  std::cout << "Hello, " << me.name() << "!\n";
  me.name("Dave");
  std::cout << "Alice is now " << me.name() << "!\n";

  Hello b("Bob");
  std::cout << "Hello, " << b.name() << "!\n";
  return 0;
}
