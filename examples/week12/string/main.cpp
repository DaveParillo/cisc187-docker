// This program demonstrates the mesa::string class.
#include <cassert>
#include <iostream>
#include <sstream>

#include "string.h"

int main()
{
  using mesa::string;
  using std::cout;
  using std::endl;

  // Define several mesa::string objects.
  string name1("Alice"), name2{"Bob"};
  auto name3 = string("vishnu");
  auto name4 = name3;
  assert (&name3 != &name4);
  assert ( &(name3.data()[0]) != &(name4.data()[0]) );
  string foo("bar");

  // Display the mesa::string object values.
  cout << "name1: " << name1.data() << endl;
  cout << "name2: " << name2 << endl;
  cout << "name3: " << name3 << endl;
  cout << "name4: " << name4 << endl;

  // Test the relational operators.
  std::cout << "test relational operators . . .\t";
  assert (name1 != name2);
  assert (name3 == name4);
  assert (name3 == string{"vishnu"});
  // assert (name3 == "bar");
  assert (name1 < name2);
  assert (name2 >= name1);
  assert (name3 > name2);
  std::cout << "OK\n";

  std::cout << "test move and copy . . .\t";
  name4 = foo;
  name4 = string("howdy");
  assert (foo == string{"bar"});


  string dest = std::move(foo);
  assert (dest == string{"bar"});
  dest += name1;
  assert (dest == string{"barAlice"});
  dest = dest + name2 + name1;
  std::cout << "OK\n";

  return 0;
}
