
//
// This is example code from Chapter 18.2.2 "Copy assignments" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

//------------------------------------------------------------------------------
#include <iostream>

class vector {
    int sz;
    double* elem;
    void copy(const vector& arg);     // copy elements from arg into *elem
public:
    vector(int s) :sz(s), elem(new double[s]) { } // constructor
    ~vector() { delete[] elem; }                  // destructor

    int size() const { return sz; }               // the current size

    double get(int n) { return elem[n]; }         // access: read
    void set(int n, double v) { elem[n]=v; }      // access: write
    vector& operator=(const vector&);             // copy assignment
};

//------------------------------------------------------------------------------

void vector::copy(const vector& arg)
// copy elements [0:arg.sz-1]
{
    for (int i = 0; i<arg.sz; ++i) elem[i] = arg.elem[i];
}

//------------------------------------------------------------------------------

// in the text book example and in the example source, 
// the copy function is called *before* delete[] elem
// end result: elem is not a copy of a, rather all set to 0
vector& vector::operator=(const vector& a)
// make this vector a copy of a
{
    delete[ ] elem;              // deallocate old space
    // the temp variable p in the text is not really needed
    elem = new double[a.sz];     // allocate new space
    copy(a);                     // copy elements
    sz = a.sz;
    return *this;                     //  return a self-reference (see §17.10)
}

//------------------------------------------------------------------------------

int main()
{
    vector v(5);
    v=v;    // self assignment

    v.set(0,3);
    v.set(1,5);
    v.set(2,8);
    v.set(3,13);
    v.set(4,21);
    vector x(5);
    x = v;
    for (int i = 0; i< x.size(); ++i) {
      std::cout << "x[" << i << "]=" << x.get(i) << '\t';
    }
    std::cout << '\n';

}

//------------------------------------------------------------------------------
