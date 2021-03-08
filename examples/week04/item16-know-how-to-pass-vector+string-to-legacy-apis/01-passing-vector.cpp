//
// Effective STL item 16: Know how to pass vector and string data to legacy APIs
//

#include "print.h"

#include <iostream>
#include <vector>
#include <cstring>

int data[] = { -30, 102, 55, -19, 0, 222, -3000, 4000, 8, -2 };
const int numValues = sizeof data / sizeof(int);

void doSomething(const int* pInts, size_t numInts) {
  int sum = 0;
  for (size_t i = 0; i < numInts; i++)
    sum += pInts[i];
  std::cout << "Sum of ints in the array is " << sum << std::endl;
}


void doSomething(const char *pString) {
  std::cout << "in doSomething, length of the string is: " << strlen(pString) << std::endl;
}

int main() {
  std::vector<int> v;
  v.insert(v.begin(), data, data + numValues);	// insert the ints in data
                                                // into v at the front
  print ("after range insert, v", v);

  doSomething(&v[0], v.size());       // ok, unless v is empty

  if (!v.empty()) {                   // safer
    doSomething(&v[0], v.size());     //&v[0] is better than v.begin()
  }

  std::string s("this is a test");
  doSomething(s.c_str());     // convert c++ string to
                              // a C null-terminated char array

  return 0;
}
