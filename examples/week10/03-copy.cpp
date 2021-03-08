#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
 
// repeat example 03, but using copy and an ostream iterator
//
int main() {
  std::vector<int> numbers {3, 1, 4, 1, 5, 9};
  std::copy(numbers.begin(), numbers.end(), 
            std::ostream_iterator<int>(std::cout));
  std::cout << '\n';

}

