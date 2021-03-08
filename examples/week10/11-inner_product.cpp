
#include <numeric>
#include <iostream>
#include <vector>


int main()
{
  std::vector<int> x = { 3,1,4,1,5,9 };
  std::vector<int> y = { 2,7,1,8,2,8 };

  int product = 
    std::inner_product(x.begin(), x.end(), y.begin(), 0, [](int a, int b){return a+b;}, std::multiplies<int>());

  std::cout << "product:\t" << product << std::endl;


}

