
//
// This is example code from Chapter 4.5.1 "Why bother with functions?" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//


#include <iostream>

//------------------------------------------------------------------------------

void print_square(int v)
{
  std::cout << v << '\t' << v*v << '\n';
}

//------------------------------------------------------------------------------

int main()
{
  for (int i = 0; i<100; ++i) print_square(i);
}

//------------------------------------------------------------------------------
