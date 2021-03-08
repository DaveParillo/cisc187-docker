
//
// This is example code from Chapter 19.3.4 "Containers and inheritance" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include <vector>
#include "Shapes.h"

using std::vector;

//------------------------------------------------------------------------------

int main()
{
    vector<Shape> vs;
    vector<Circle> vc;
    //vs = vc;       // error: vector<Shape> required
    void f(vector<Shape>&);
    //f(vc);         // error: vector<Shape> required

    vector<Shape*> vps;
    vector<Circle*> vpc;
    //vps = vpc;     // error: vector<Shape*> required
    void f(vector<Shape*>&);
    //f(vpc);        // error: vector<Shape*> required
}

//------------------------------------------------------------------------------

void f(vector<Shape*>& v)
{
    v.push_back(new Rectangle(Point(0,0),Point(100,100)));
}

//------------------------------------------------------------------------------
