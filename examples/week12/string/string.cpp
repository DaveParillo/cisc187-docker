#include <cstring>
#include <algorithm>
#include <iostream>

#include "string.h"

// mesa::string& mesa::string::operator=(const mesa::string& rhs)
// {
//    if (sz != 0) delete [] str;
//    str = new char[rhs.sz + 1];
//    std::strcpy(str, rhs.str);
//    sz = rhs.sz;
//    return *this;
// }

// mesa::string& mesa::string::operator=(mesa::string&& rhs)
// {
//    if (this != &rhs) {
//      std::swap(str, rhs.str);
//      std::swap(sz, rhs.sz);
//    }
//    return *this;
// }

mesa::string& mesa::string::operator+=(const mesa::string& rhs)
{
  char *tmp = str;
  str = new char[sz + rhs.sz + 1];
  std::strcpy(str, tmp);
  std::strcat(str, rhs.str);
  if (sz != 0) {
    delete [] tmp;
  }
  sz = std::strlen(str);
  return *this;
}

std::ostream& operator<<(std::ostream& os, const mesa::string& obj)
{
  return os << obj.data();
}

std::istream& operator>>(std::istream& is, mesa::string& rhs)
{
  is.getline(rhs.data(), rhs.size());
  return is;
}

