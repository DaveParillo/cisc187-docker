//
// From the overload and template tutorial at
// http://www.cplusplus.com/doc/tutorial/functions2/
//


#include <iostream>

int operate (int a, int b) {
  return (a*b);
}
double operate (double a, double b) {
  return (a/b);
}

int main () {
  int x=5,y=2;
  double n=5.0,m=2.0;
  std::cout << operate (x,y) << '\n';
  std::cout << operate (n,m) << '\n';
}


