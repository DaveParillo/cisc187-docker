
//
// This is example code from Chapter 21.4.3 "Lambda expressions" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

struct Record {
    string name;        // standard string for ease of use
    char addr[24];    // old style to match database layout
    // ...
};

//------------------------------------------------------------------------------

int main()
{
    vector<Record> vr;

    // ...
    sort(vr.begin(), vr.end(),     // sort by name
        [](const Record& a, const Record& b) 
            {return a.name < b.name; }
        );
    // ...
    sort(vr.begin(), vr.end(),     // sort by addr
        [](const Record& a, const Record& b) 
            {return strncmp(a.addr, b.addr, 24) < 0; }
        );
    // ...
}

//------------------------------------------------------------------------------
