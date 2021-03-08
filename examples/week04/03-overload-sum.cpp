//
// From the overload and template tutorial at
// http://www.cplusplus.com/doc/tutorial/functions2/
//


#include <iostream>

int sum (int a, int b) {
  return (a+b);
}
double sum (double a, double b) {
  return (a+b);
}

int main () {
  int x=5,y=2;
  double n=5.45,m=2.55;
  std::cout << sum (x,y) << '\n';
  std::cout << sum (n,m) << '\n';
}


