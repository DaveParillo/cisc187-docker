// Another thing every c++ programmer should know, 
// but where is the best place to introduce this ...
//
// Some important notes abot bit fields
// Because bit fields do not necessarily begin at the beginning of a byte, 
// address of a bit field cannot be taken. 
//
// Pointers and non-const references to bit fields are not possible. 
// 
// When initializing a const reference from a bit field, 
// a temporary is created (its type is the type of the bit field), 
// copy initialized with the value of the bit field, 
// and the reference is bound to that temporary.
// 
// The type of a bit field can only be integral or enumeration type.
// A bit field cannot be a static data member.
// 
// See http://en.cppreference.com/w/cpp/language/bit_field
#include <iostream>

using std::cout;

// an overly simplified date struct
struct date
{
  bool bce;
  unsigned int d;
  unsigned int m;
  unsigned int y;
};

std::ostream& operator<<(std::ostream& os, const date& d) {
  return os << d.y << '-' << d.m << '-' << d.d << (d.bce? " BCE":"");
}

struct short_date
{
  bool bce: 1;
  unsigned int d: 5;  // 5 bits are just enough for 0 - 31
  unsigned int m: 4;  // valid for 0 - 15, only need up to 12
  unsigned int y: 12; // valid for 0 - 4095
};

std::ostream& operator<<(std::ostream& os, const short_date& d) {
  return os << d.y << '-' << d.m << '-' << d.d << (d.bce? " BCE":"CE");
}

int main() {
  struct date d = {false,4,7,1776};
  struct short_date sd = {false,4,7,1776};

  cout << "sizeof date: " << sizeof(date) << ", " << sizeof(date) * 8 << " bits\n";
  cout << "sizeof short_date: " << sizeof(short_date) << ", " << sizeof(short_date) * 8 << " bits\n";

  cout << "date: " << d << '\n';
  cout << "short: " << sd << '\n';
  d  = {true,1,1,399};
  sd = {true,1,1,399};
  cout << "archimedes died: " << d << '\n';
  cout << "archimedes died: " << sd << '\n';

  return 0;
}
