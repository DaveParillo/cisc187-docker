
//
// This is example code from Chapter 19.5.4 "unique_ptr" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// Prefer returning a unique_ptr to avoid pointer ownership problems
// instead of returning vector<int>*

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

using std::unique_ptr;
using std::vector;

unique_ptr<vector<int>> make_vec()    // make a filled vector
{
  unique_ptr<vector<int>> p{new vector<int>}; // allocate on free store
  // fill the vector with data; this may throw an exception
  return p;  // requires a move constructor
}

int main() 
{
  try
  {
    unique_ptr<vector<int>> p(make_vec());
  }
  catch (std::exception& e) {
    std::cerr << "error: " << e.what() << '\n'; 
    return 1;
  }
  catch (...) {
    std::cerr << "Oops: unknown exception!\n"; 
    return 2;
  }
  return 0;
}

