#include <map>
#include <iostream>

int main()
{
  std::multimap<int, int> x {{2, 7}, {1, 8}, {2, 8}, 
                             {1, 8}, {2, 8}, {4, 5}};
  for (auto i: x) {
    std::cout << i.first << ',' << i.second << ' ';
  }
}

