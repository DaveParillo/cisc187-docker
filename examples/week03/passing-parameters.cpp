
#include <cassert>
#include <iostream>

/**
 * A copy of x is passed to this function.
 * Changes to x are not reflected in the caller.
 */
void by_value(int x)
{
  assert(x == 11);
  x = 99;
  assert(x == 99);
}

/**
 * A reference to x is passed to this function.
 * Changes to x are not reflected in the caller.
 *
 * What if the signature is changed to 'const int& x'?
 */
void by_reference(int& x)
{
  assert(x == 11);
  std::cout << "in by_ref the address of x is   " << &x << '\n';
  x = -1;
  assert(x == -1);
}

int main()
{
  auto alpha = 11;
  auto beta = 11;

  std::cout << "in main the address of alpha is " << &alpha << '\n';
  std::cout << "in main the address of beta is  " << &beta << '\n';

  by_value(alpha);
  by_reference(beta);
  assert(alpha == 11);
  assert(beta  == -1);

  std::cout << "alpha is now " << alpha << '\n';
  std::cout << "beta is now " << beta << '\n';
  return 0;
}



