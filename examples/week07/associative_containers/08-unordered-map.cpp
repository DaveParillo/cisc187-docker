#include <unordered_map>
#include <iostream>

int main()
{
  std::unordered_map<int, int> x {{3, 1}, {4, 1}, {5, 9}, 
                                  {2, 6}, {5, 3}, {9, 2}};
  for (auto i: x) {
    std::cout << i.first << ',' << i.second << '\n';
  }
}

