
//
// This is example code from Chapter 19.2.3 "Resize" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// Try this:
//
// What cases do we need to consider (and test) if we want to convince ourselves 
// that this resize() is correct?
//
// How about newsize == 0?
// How about newsize == -77?
//

#include <iostream>
//------------------------------------------------------------------------------

class vector {
    int sz;       // number of elements
    double* elem; // address of first element
    int space;    // number of elements plus "free space"/"slots"
                  // for new elements ("the current allocation")
public:
    vector();
    void reserve(int newalloc);
    int  capacity() const;
    void resize(int newsize);
    // ...
};

//------------------------------------------------------------------------------

vector::vector() :sz(0), elem(0), space(0) {}

//------------------------------------------------------------------------------

void vector::reserve(int newalloc)
{
    if (newalloc<=space) return;             // never decrease allocation
    double* p = new double[newalloc];        // allocate new space
    for (int i=0; i<sz; ++i) p[i] = elem[i]; // copy old elements
    delete[ ] elem;                          // deallocate old space
    elem = p;
    space = newalloc;        
}

//------------------------------------------------------------------------------

int vector::capacity() const { return space; }

//------------------------------------------------------------------------------

void vector::resize(int newsize)
// make the vector have newsize elements
// initialize each new elements with the default value 0.0
{
    reserve(newsize);
    for (int i=sz; i<newsize; ++i) elem[i] = 0;    // initialize new elements 
    sz = newsize;    
}

//------------------------------------------------------------------------------

int main()
{
    vector v;
    v.reserve(10);
    v.resize(4);
    std::cout << "resize: 4 , cap: " << v.capacity() << std::endl;
    v.resize(0);
    std::cout << "resize: 0 , cap: " << v.capacity() << std::endl;
    v.resize(-77);
    std::cout << "resize: -77 , cap: " << v.capacity() << std::endl;
    v.resize(999999999999999);
    std::cout << "resize: 999999999999999 , cap: " << v.capacity() << std::endl;
    v.resize(-999999999999999);
    std::cout << "resize: -999999999999999 , cap: " << v.capacity() << std::endl;
}

//------------------------------------------------------------------------------
