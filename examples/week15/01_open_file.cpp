#include <fstream>
#include <iostream>
#include <string>

int main()
{
  std::cout << "Please enter input file name: ";
  std::string iname;
  std::cin >> iname;
  std::ifstream ist {iname};  // ifstream is an “input stream from a file”
                              // defining an ifstream with a name string
                              // opens the file of that name for reading
  if (!ist) {
    std::cerr << "can't open input file " << iname;
  }
  return 0;
}
