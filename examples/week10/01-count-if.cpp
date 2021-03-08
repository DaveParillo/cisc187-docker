#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  std::vector<int> numbers { 1, 2, 3, 4, 5, 
                            10, 15, 20, 25, 
                            35, 45, 50 };
  auto gt_5 = std::count_if(numbers.begin(), 
                            numbers.end(), [](int x) { return (x > 5); });
  std::cout << "The # of elements > 5 is: "
            << gt_5 << ".\n";
}
