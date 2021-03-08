//
// floating point values have two ways to represent zero
//
// see:
// https://en.wikipedia.org/wiki/Signed_zero
// and
// http://www.volkerschatz.com/science/float.html
//
#include <bitset>
#include <iostream>

using std::cout;
using std::bitset;


int main() {

  // C++ integral types store negatives as the two's complement
  // of the positive number.
  //   1. Makes most arithmetic consistent for negative & pos numbners
  //   2. No inconsistency representing 0
  int x = -1;
  int y = ~x;  // one's complement of x
  int z = x * 0;

  cout << "x: " << x << "\t(" << bitset<4>(x) << ")\n";
  cout << "y: " << y << "\t(" << bitset<4>(y) << ")\n";
  cout << "z: " << z << "\t(" << bitset<4>(z) << ")\n";
  cout << "~z: " << ~z << "\t(" << bitset<4>(~z) << ")\n";

  // The IEEE standard for floating point numbers requires both +0 and −0
  double u = -1.0;
  double v = u * 0.0;
  double w = v * -1.0;

  cout << "u: " << u << '\n';
  cout << "v: " << v << '\n';
  cout << "w: " << w << '\n';

  cout << " value \t binary \tone's complement \n";
  cout << " ===== \t ====== \t================ \n";
  for (int i = -4; i< 8; ++i) {
    cout << "  " << i << '\t' << bitset<4>(i) << "\t\t" << ~i << '\t' << bitset<4>(~i) << '\n';
  }
}
