//
// Print all the odd numbers between 1 and 100, inclusive
//
#include <iostream>
using std::cout;

int main() {
  cout << "Odd numbers:\n";
  for (int num = 1; num <= 100; ++num) {
    if (num % 2 != 0) {
      cout << '\t' << num << '\n';
    }
  }
}
