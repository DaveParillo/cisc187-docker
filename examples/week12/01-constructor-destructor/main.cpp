#include "Hello.h"
#include <iostream>

using std::cout;

Hello g("Global");

int main() {
  cout << "entering main\n";
  cout << "Hello, " << g.name() << "!\n";

  Hello al;
  cout << "Hello, " << al.name() << "!\n";

  cout << "leaving main\n";
  return 0;
}
