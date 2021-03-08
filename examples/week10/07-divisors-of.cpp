#include <iostream>
#include <algorithm>
#include <vector>

void divisible_by(const std::vector<int>& numbers, const int divisor);

int main()
{
  std::vector<int> numbers { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
  divisible_by(numbers, 3);
  divisible_by(numbers, 5);

}

void divisible_by(const std::vector<int>& numbers, const int divisor)
{

  std::cout << "Values divisible by " << divisor << std::endl;
  // print all the numbers divisible by divisor
  for_each(numbers.begin(), numbers.end(), 
      [divisor] (int y) {
        if (y % divisor == 0) {
          std::cout << y << std::endl;
        }
      });
}


