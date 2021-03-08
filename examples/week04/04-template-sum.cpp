//
// From the overload and template tutorial at
// http://www.cplusplus.com/doc/tutorial/functions2/
//


#include <iostream>

template <class T> T sum (T a, T b) {  
  return a+b;
}

int main () {
  std::cout << sum<int> (10,20) << '\n';
  std::cout << sum<double> (1.0,1.5) << '\n';

  // or let the compiler deduce the type
  std::cout << sum (10,20) << '\n';
  std::cout << sum (1.0,1.5) << '\n';
}


