#include <iostream>
#include <set>

int main()
{
  std::set<int> x {2,7,1,8,2,8,1,8,2,8,4,5,9};

  for (const auto& i: x) {
    std::cout << i << ' ';
  }
  std::cout << "\n\ninsert 6:\n";
  x.insert(6);
  for (const auto& i: x) {
    std::cout << i << ' ';
  }
  // erase 2
  auto it = x.find(2);
  if(it != x.end()) {
    std::cout << "\n\nerase " << *it << ":\n";
    x.erase(it);
  } else {
    std::cout << "not found\n";
  }
  for (const auto& i: x) {
    std::cout << i << ' ';
  }
}

