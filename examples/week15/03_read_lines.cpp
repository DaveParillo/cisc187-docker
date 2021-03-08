#include <fstream>
#include <iostream>
#include <string>


int main () {
  std::string str = "poem.txt";
  std::ifstream is(str);     // open file

  std::string line;
  while (getline(is, line)) {
    std::cout << line << std::endl;
    line.clear();
  }

  is.close();                // close file

  return 0;
}
