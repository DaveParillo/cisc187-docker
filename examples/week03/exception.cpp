//
// A simple example of executing code that throws an exception
//
// Allocate 1MB blocks of memory until no more can be allocated.


#include <iostream>

int main() {
  try {
    int i = 0;
    while (true) {
      if ((i % 1000) == 0) std::cout << i << " MB\n";
      ++i;
      double* pd = new double[131072];    // let's leak 1 MB, woot!
    }
  }
  // this is the exception I expect to be thrown
  // specifying a const& parameter is considered a best practice
  catch (const std::bad_alloc& e) {
    std::cerr << "exception: " << e.what() << std::endl;
  }
  // this special syntax will catch ANY exception
  // before doing this, ensure you are prepared to correctly
  // handle anything!
  catch (...) {
    std::cerr << "some other exception\n";
  }
}

