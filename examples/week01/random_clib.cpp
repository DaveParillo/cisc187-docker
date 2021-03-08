//
// Create 10 random numbers using C libraries
//
// Note that rand() on older compilers is neither very random or thread safe
//

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
  std::cout << "Random numbers: \n";
  srandom(time(0));            // seed the random number generator
  for (int i = 0; i < 10; ++i) {
    std::cout << random() << '\n';
  }
}
