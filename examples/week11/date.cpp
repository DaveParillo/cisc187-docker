#include "date.h"  // your includes should be first

#include <tuple>
// could have implemented default constructor here
// date::date () 
//  : y{1776}, m{7}, d{4}
// { } \m[]

date::date (int year, int mon, int day)
    : y{year}, m{mon}, d{day}
{ }

std::tuple<int,int,int> date::as_tuple () {
    return std::make_tuple(y, m,d);
}

// simple accessors like these are commonly implemented
// directly in the interface
int date::year ()  { 
    return y; 
}

int date::month () { 
    return m; 
}

int date::day ()   { 
    return d; 
}

