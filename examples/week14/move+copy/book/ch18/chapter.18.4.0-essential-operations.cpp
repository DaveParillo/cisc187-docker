
//
// This is example code from Chapter 18.4 "Essential operations" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <string>
#include <vector>

using namespace std;


//------------------------------------------------------------------------------

int main()
{
    string s("Triumph");           // initialize s to the character string "Triumph"
    vector<double> v(10);          // make v a vector of 10 doubles

    vector<double> vi(10);         // vector of 10 doubles, each initialized to 0.0
    vector<string> vs(10);         // vector of 10 strings, each initialized to ""
    vector<vector< int> > vvi(10); // vector of 10 vectors, each initialized to vector()
}

//------------------------------------------------------------------------------
