#include <iostream>
#include <map>
#include <string>
#include <utility>

//
// A std::pair is used to store a pair of related values
//
int main () {
  std::pair<int, int> pair {3, 1};
  std::cout << "first is " << pair.first << ", second is " << pair.second << ".\n";

  std::map<std::string, int> inventory {
    {"apple", 12},
    {"kiwi", 4},
    {"grape", 100},
  };

  std::map<std::string, int> copy(inventory);

  std::pair<std::string, int> banana;
  banana = std::make_pair("banana", 5);

  inventory.insert(banana);
  inventory.insert(std::make_pair("lemon", 1));
  std::cout << "inventory: \n";
  for (const auto& i: inventory) {
    std::cout << i.first << '\t' << i.second << '\n';
  }
  return 0;
}

