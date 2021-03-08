#include <iostream>

// A pointer can point to anything, even another pointer.
// Each new pointer justs ands another to the chain of pointers
// The language does not impose a strict limit
// The only limit is your sanity...
int main()
{
  int x = 8;
  int* p2x = &x;
  int** p2p = &p2x;
  int*** p2pp = &p2p;    // now we're just being silly ...

  std::cout << "x: " << *p2x << '\n';
  std::cout << "x: " << **p2p << '\n';
  std::cout << "x: " << ***p2pp << '\n';

  return 0;
}

