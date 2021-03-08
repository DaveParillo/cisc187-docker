#include <iostream>
#include <map>
#include <string>

int main()
{
  std::map<std::string, int> name_counts {{"Alice", 27}, 
                                          {"Bob", 3}, 
                                          {"Clara", 1}};

  for (const auto& pair : name_counts) {
    std::cout << pair.first << ": " 
              << pair.second << '\n';
  }
  name_counts["Bob"] = 42;   // update existing value
  name_counts["Darla"] = 9;  // insert a new value

  // get map values
  std::cout << "Alice is " << name_counts.find("Alice")->second << '\n';
  std::cout << "Bob is " << name_counts.at("Bob") << '\n';
  std::cout << "Darla is " << name_counts["Darla"] << '\n';
}

