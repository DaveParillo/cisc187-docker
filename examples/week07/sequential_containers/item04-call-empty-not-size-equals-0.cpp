// 
// Effective STL item #4: Call empty instead of checking size() against zero.
//
// From Effective STL by Scott Meyers (Addison-Wesley Professional). 
// Copyright 2001 Scott Meyers, 978-0-201-74962-5.
//
// In most containers, calling size() is constant time.
// That is it takes the same amount of time regardless of 
// the number items in the container.
// Not so for lists.
//
// Consider the following program:

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using std::list;

template<typename Container>
void print(const std::string& name, const Container& c) {

  std::cout << name << ": \t";
  for (auto v: c) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
}


int main() {
  const int vals1[] = { 1, 2, 3, 4, 5};
  const int nvals1 = sizeof vals1 / sizeof(int);

  const int vals2[] = { -3, 2, 5, 6, 9, 102, -15, 10 , 11, 12};
  const int nvals2 = sizeof vals2 / sizeof(int);

  list<int> list1(vals1, vals1 + nvals1);
  list<int> list2(vals2, vals2 + nvals2);

  std::cout << "Before:\n";
  print("list1", list1);
  print("list2", list2);

  list1.splice(                                     // move all nodes in list2
      list1.end(), list2,                           // (from the first occurrence
      find(list2.begin(), list2.end(), 5),          // of 5 up to but not
      find(list2.rbegin(), list2.rend(), 10).base() // including the last
      );                                            // occurrence of 10) to the
                                                    // end of list1. See Item 28
  std::cout << "After:\n";
  print("list1", list1);
  print("list2", list2);
  return 0;
}

// Quoted from Effective STL #4:
//
// This code won't work unless list2 contains a 10 somewhere beyond a 5, 
// but let's assume that's not a problem. 
// Instead, let's focus on this question: 
// how many elements are in list1 after the splice? 
//
// Clearly, list1 after the splice has as many elements as it did before 
// the splice plus however many elements were spliced into it. 
// But how many elements were spliced into it? As many as were in the range 
// defined by 
// find(list2.begin(), list2.end(), 5) and 
// find(list2.rbegin(), list2.rend(), 10).base(). 
//
// Okay, how many is that? 
// Without traversing the range and counting them, there's no way to know. 
// And therein lies the problem.


