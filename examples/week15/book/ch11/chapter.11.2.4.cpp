
//
// This is example code from Chapter 11.2.4 "Precision" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <iostream>
#include <iomanip>

using namespace std;

inline ios_base& general(ios_base& b)    // to complement fixed and scientific
{
    b.setf(ios_base::fmtflags(0), ios_base::floatfield);
    return b;
}

//------------------------------------------------------------------------------

int main()
{
    cout << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
    cout << general << setprecision(5)
         << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
    cout << general << setprecision(8)
         << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << '\n';
}

//------------------------------------------------------------------------------
