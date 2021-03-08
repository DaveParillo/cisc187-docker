#include <bitset>
#include <iostream>

using std::cout;
using std::bitset;

int main ()
{
  short x = 5;
  short y = 10;
  auto  z = x|y;

  cout << x << " in binary is:\t\t" << bitset<8>(x) << '\n';
  cout << y << " in binary is:\t" << bitset<8>(y) << '\n';
  cout << x << '|' << y << " in binary is:\t" << bitset<8>(z) << " = " << z << '\n';
  cout << x << '&' << z << " in binary is:\t" << bitset<8>(x & z) << '\n';
  cout << y << " shifted 4 left is:\t" << bitset<8>(x << 4) << '\n';
  cout << x << " shifted 1 right is:\t" << bitset<8>(x >> 1) << '\n';
  return 0;
}

