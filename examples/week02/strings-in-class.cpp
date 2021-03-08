#include <cstdio>
#include <iomanip>
#include <iostream>
#include <locale>
#include <string>

int main() {
  // char  a[]  = {'h', 'e', 'l', 'l', 'o', '\0'};
  // char  b[]  = {'l', 'o', 0};
  // char  c[6] = {'h', 'e', 'l', 'l', 'o', '\0'};

  std::string a, b, c;
  // std::string x();
  std::string s = {"there!"};
  a = "hello ";
  b = a;
  s = a + s;
  std::cout << std::boolalpha;
  std::cout << s << ' ' << s.size() << s.empty() << '\n';
  // std::cout << s[0] << s.back() << '\n';
  
  s[s.size()-1] = 'x';
  std::cout << s << "last: " << s[s.size() -1 ] << '\n';
  char& last = s.back();
  last = 'y';
  std::cout << s << "last: " << s.back() << '\n';
  last = std::toupper(last, std::locale());
  std::cout << "uppercase? " << s << '\n';

  b = "123";
  c = "123x";

  std::cout << (b.find_first_not_of("0123456789") == std::string::npos) << '\n';
  std::cout << (c.find_first_not_of("0123456789") == std::string::npos) << '\n';

  s.append(" wow, this is boring dave ");
  s.append(3, '#');
  s += c;
  s.push_back('?');
  s.insert(5, 2, '*');
  std::cout << s << '\n';


  printf ("%s %s\n", b.c_str(), &s[0]);


  return 0;
}
