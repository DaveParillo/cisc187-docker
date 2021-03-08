//
// Effective STL item 6: Be alert for C++'s most vexing parse.
//

#include <list>
#include <iostream>
#include <fstream>

using std::istream_iterator;
using std::list;

int f(double d);   // declare a function f taking a double, returning an int
int f(double(d));  // same as above; parens around d are ignored
int f(double);     // same as above; parameter name is omitted

// now repeat these declarations with function pointers

int g(double (*pf)());  // g takes a pointer to a function as a parameter
int g(double pf());     // same as above; pf is implicitly a pointer
int g(double ());       // same as above; parameter name is omitted

// In the above,
// notice the difference between parentheses around a parameter name 
// (such as d in the second declaration for f) and 
// standing by themselves (as in this example). 
//
// Parentheses around a parameter name are ignored, 
// but parentheses standing by themselves indicate the existence of a parameter list: 
// they announce the presence of a parameter that is itself a pointer to a function.

int main() {

  std::ifstream dataFile("ints.dat");



  //	This scope *appears* to declare a list of ints using a file to initialize it
  //	{
  //		list<int> data(istream_iterator<int>(dataFile), istream_iterator<int>());
  //
  //		cout << "First value in the list is " << *data.begin() << endl;
  //	}
  //	Actually, no it doesn't.
  //
  //	This declares a function, data, whose return type is list<int>. 
  //	The function data takes two parameters:
  // 􏰀 The first parameter is named dataFile. It's type is istream_iterator<int>. 
  //   The parentheses around dataFile are superfluous and are ignored.
  //     Just as in the second definition of f above.
  //
  // 􏰀 The second parameter has no name. 
  //   Its type is pointer to function taking nothing and returning an istream_iterator<int>.


  //  correct, but doesn't work with some compilers:
  //	{
  //		list<int> data((istream_iterator<int>(dataFile)),	istream_iterator<int>())
  //                   ^                               ^
  //      note new parens around 
  //      first argument to list constructor
  //
  //		cout << "First value in the list is " << *data.begin() << endl;
  //	}


  /* should always work: */
  {
    istream_iterator<int> dataBegin(dataFile);
    istream_iterator<int> dataEnd;
    list<int> data(dataBegin, dataEnd);	

    std::cout << "First value in the list is " << *data.begin() << '\n';
  }
  return 0;
}
