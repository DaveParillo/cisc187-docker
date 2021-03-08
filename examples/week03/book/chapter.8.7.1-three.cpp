
//
// This is example code from Chapter 8.7.1 "Using declarations and using directives" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <string>

using namespace std;
//------------------------------------------------------------------------------

int main()
{
    string name;
    cout << "Please enter your first name\n";
    cin >> name;
    cout << "Hello, " << name << '\n';
}

//------------------------------------------------------------------------------
