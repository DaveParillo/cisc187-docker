#include <iostream>
#include <algorithm>
#include <vector>

int sum_divisible_by(const std::vector<int>& numbers, const int divisor);

int main()
{
  std::vector<int> numbers { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
  std::cout << "Sum: " << sum_divisible_by(numbers, 5) << std::endl;

}

int sum_divisible_by(const std::vector<int>& numbers, const int divisor)
{
  int sum = 0;
  
  for_each(numbers.begin(), numbers.end(), 
      [divisor, &sum] (int y) {
        if (y % divisor == 0) {
          sum += y;
        }
      });

  return sum;
}


