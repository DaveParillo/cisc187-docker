#ifndef WEEK04_OVERLOAD_H
#define WEEK04_OVERLOAD_H

// C++ allows function names to be 'overloaded'
// that is, used more than once
//
// The one requirement is that the parameter lists must be different
int    square(const int x);
double square(const double x);
//float  square(const float x);  // bad declaration: conflicts with double square()
//float  square(const double x); // bad declaration: redundant, only return type is different

#endif
