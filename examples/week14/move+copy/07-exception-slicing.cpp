#include <stdio.h>

// This is a common error and why we prefer
// passing by const& instead by value
//
// The exception thrown from ouch() is sliced
// in the catch block of main
//
// Borrowed from http://cppquiz.org/quiz/question/33

struct GeneralException {
  virtual void print() { puts("G"); }
};

struct SpecialException : public GeneralException {
  void print() override { puts("S"); }
};

void ouch() { throw SpecialException(); }

int main() {
  try {
    ouch();
  }
  catch (GeneralException e) {
    e.print();
  }
}

