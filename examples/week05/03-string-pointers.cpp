#include <iostream>
#include <string>

// pointers like this string pointer can also point to pointers
using std::string;
using std::cout;

int main() {
  string message[] = {"Alice","Bob here!","Carol checking in."};

  string *sp;   // a pointer to at least 1 string

  sp = message;
  cout << "sp:\n";
  cout << sp << '\n';
  cout << *sp << '\n';
  cout << *(sp + 1) << '\n';
  cout << *(sp + 2) << "\n\n";


  cout << "sp2:\n";
  string *sp2 = new string [3];          //create string pointer on the heap
  *sp2 = "\nAlice has left the building";
  *(sp2 + 1) = "Bob who?";
  *(sp2 + 2) = "Carol checked out.";

  cout << sp2 << '\n';
  cout << *sp2 << '\n';
  cout << *(sp2 + 1) << '\n';
  cout << *(sp2 + 2) << '\n' << '\n';

  string **sp3;                 // a pointer to a string pointer

  cout << "sp3:\n";
  sp3 = &sp2;
  cout << sp3 << '\n';
  cout << **sp3 << '\n';

  delete[] sp2;
}
