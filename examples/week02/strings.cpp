#include <string>
#include <iostream>
#include <cstdio>

using std::string;

int main()
{
  string a = "hello";
  a += ", world!";        // joining strings is pretty easy

  string b = a;           // so is copying one string into another

  if (a == b) {
    b[0] = 'H';           // and a string feels like an 'array of char' 
    b[7] = 'W';
  }

  std::cout << a << '\n';
  std::cout << b << '\n';

  // one common point of confusion: 
  auto x = "Goodbye";          // x is NOT a string: it is const char*
  //auto y = "everyone"s;      // y defines a string literal in C++14
  auto y = string{"everyone"}; // y is a std::string

  std::cout << x << ", " << y << '\n';

  // Also, you cannot use std::string in a function 
  // that expects const char* - you must convert it
  // to a null terminated character array

  //printf ("Hello again, %s\n", y);       // compile error
  printf ("Hello again, %s\n", y.c_str()); // the c_str() function converts a string

}
     
