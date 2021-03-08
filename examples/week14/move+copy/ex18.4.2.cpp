
//
// Based on example code from Chapter 18.4.2 "Debugging constructors and destructors" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// Added some verbosity to help illustrate what's happening each step of the way.
// There is a lot going on in this one tiny program and it's important to 
// be able to follow along.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------

struct X {    // simple test class
    int val;

    void out(const string& s, const bool lf)
    { 
      if (!lf) cerr << '\t' << this <<  "->"; 
      cerr << s << ": " << val << ' '; 
      if (lf) cerr << '\n';
    }
    // default constructor
    X()
    { 
      out("X()", false); 
      val=1; 
      out("X() after", true); 
    }

    // one arg constructor
    X(int v) 
    { 
      out( "X(int)", false); 
      val=v; 
      out( "X(int) after", true); 
    }

    // copy constructor
    X(const X& x)
    { 
      out("X(X&) ", false); 
      val=x.val; 
      out( "X(X&) after", true); 
    }
    // move constructor
    X(X&& x)
    { 
      out("X(X&&) ", false); 
      val=x.val; 
      x.val = 0; 
      out( "X(X&&) after", true); 
    }

    X& operator=(const X& a) 
    { 
      out("X::operator=()", false); 
      val=a.val; 
      out("X::operator=() after", true); 
      return *this; 
    }
    ~X() { out("~X()", true); }
};

//------------------------------------------------------------------------------

X glob(2);            // a global variable

X copy(X a) { return a; }

X copy2(X a) { X aa = a; return aa; }

X& ref_to(X& a) { return a; }

X* make(int i) { X a(i); return new X(a); }

struct XX { X a; X b; };

void msg (const string& m)
{
  cout << m << "\t\t";
}
//------------------------------------------------------------------------------

int main()
{
  cout << "in main\n";
  msg("X alpha(4)");           X alpha(4);        // local variable
  msg("X beta = alpha");       X beta = alpha;
  msg("alpha = X(5)");         alpha = X(5);
  msg("b = copy(a)");          beta = copy(alpha); 
  msg("b = copy2(a)");         beta = copy2(alpha);
  msg("X gamma(6)");           X gamma(6);
  msg("X& r = ref_to(gamma)"); X& r = ref_to(gamma);

  cerr << "&r: " << &r << ", val: " << r.val << endl;

  msg("delete make(7)");       delete make(7); 
  msg("X* delta =  make(8)");  X* delta = make(8);
  msg("delete delta");         delete delta;


  msg("vector<X> v(4)");       vector<X> v(4); 
  msg("XX echo");              XX echo;
  msg("X* p = new X(9)");      X* p = new X(9);    // an X on the free store
  delete p;

  msg("an array of X's on the free store\n");
  X* pp = new X[5];    // an array of Xs on the free store
  delete[] pp;

  cout << "leaving main\n";
}

//------------------------------------------------------------------------------
