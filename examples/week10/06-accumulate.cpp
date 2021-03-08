
#include <array>
#include <numeric>
#include <iostream>
#include <list>


int main()
{
  std::array<double,4> a = { {1.1, 2.2, 3.3, 4.4} };
  std::cout << "array product:\t";
  std::cout << std::accumulate(a.begin(),a.end(), 1.0, std::multiplies<double>());
  std::cout << std::endl;
  std::list<double> ld = { 1.1, 2.2, 3.3, 4.4 };
  double product = 
    std::accumulate(ld.begin(), ld.end(), 1.0, std::multiplies<double>());

  std::cout << "product:\t" << product << std::endl;


}

