#include <fstream>
#include <iostream>
#include <string>


int main () {
  std::string str = "poem.txt";
  std::ifstream is(str);     // open file

  char c;
  while (is.get(c))          // loop getting single characters
    std::cout << c;

  is.close();                // close file

  return 0;
}
