
#include <iostream>

// Declare a function that takes a parameter.
void printFavorite(const int x);

int main() {
  printFavorite(72);  // Call the function.
  return 0;
}

// define the function
void printFavorite(const int x) {
  std::cout << "my favorite number is " << x << '\n';
}

