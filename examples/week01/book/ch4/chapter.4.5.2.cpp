
//
// This is example code from Chapter 4.5.2 "Function declarations" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//


#include <iostream>

//------------------------------------------------------------------------------

int    square(int);    // declaration of square
double sqrt(double);   // declaration of sqrt

int main()
{
    int x = square(44);
}

//------------------------------------------------------------------------------

int square(int x)      // definition of square
{
    return x*x;
}

//------------------------------------------------------------------------------
