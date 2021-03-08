#include <iostream>
#include <string>
#include <typeinfo>
#include "concepts.h"

using std::cout;

// what if we want our tmeplate to do more than return the same type it's given?
// we could modify our sum template to deduce the return type
//
// But the compiler often doesn't have enough information 
// to figure out the return type only from the template arguments.
//
// decltype to the rescue.
// Can be used anywhere, but very handy after a function declaration
// -> defines a 'trailing return type'
// auto is a placeholder and gets the return type from decltype

template <Number lhsT, Number rhsT> 
auto sum (lhsT a, rhsT b) -> decltype(a+b) {  
  return a+b;
}

int main () {
  int i = 13;
  const char* cstr = "this is a C-string";
  std::string str = "this is a C++ string";
  auto x = std::string("\tthis is a C++ string");
  decltype(x) y;  // deduce the type of y using the expression (x)

  // normally we never care about the name returned from the typeid operator
  // Typically used to compare 2 types:
  // if (typeid(a) == typeid(b)) { ...
  cout << "type of i is " << typeid(i).name() << '\n';
  cout << "type of cstr is " << typeid(cstr).name() << '\n';
  cout << "type of str is " << typeid(str).name() << '\n';
  cout << "type of x is " << typeid(x).name() << '\n';
  cout << "type of y is " << typeid(y).name() << '\n';

  std::cout << sum (10,25.5) << '\n';
  std::cout << sum (cstr,x) << '\n';

  return 0;
}



