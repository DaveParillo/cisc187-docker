
#include <iostream>
#include <list>
#include <vector>

using std::list;
using std::vector;

// a generic sum algorithm
// Compute the sum of all the elements in an array

template<class Iter, class T>
T sum(Iter first, Iter last, T s)
{
  while (first != last) {
    s = s + *first;
    ++first;
  }
  return s;
}


int main()
{
  float a[] = {1,1,2,3,5,8,13,21,34,55};
  float* end = a+sizeof(a)/sizeof(*a);
  std::cout << "My array total: " << sum (a, end, 0) << std::endl;

  list<int> foo = {3,1,4,1,5,9,5,6,2,6};
  std::cout << "My list total: " << sum (foo.begin(), foo.end(), 0) << std::endl;


  return 0;
}

