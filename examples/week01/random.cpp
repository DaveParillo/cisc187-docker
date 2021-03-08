//
// Create 10 random numbers using C++ libraries
//

#include <iostream>
#include <random>

int main() {
  std::cout << "Random numbers: \n";
  // Seed with a real random value, if available
  std::random_device r;
  std::default_random_engine eng(r());  // make a random number generator

  for (int i = 0; i < 10; ++i) {
    // generate the next uniformly distributed integer between 0 and max
    // using the random default engine
    std::cout << std::uniform_int_distribution<int> {0, 999} (eng) << '\n';
  }
}
