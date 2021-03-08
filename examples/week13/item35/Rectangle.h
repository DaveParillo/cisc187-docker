#pragma once

// from Effective C++, item # 35
//
// Does is make sense for a Square to inherit from Rectangle?

#include <iostream>

using std::size_t;

class Rectangle {
  public:
    virtual ~Rectangle(){}
    virtual void   height(size_t new_height);
    virtual void   width (size_t new_width);
    virtual size_t height() const;
    virtual size_t width()  const;
  private:
    size_t _ht = 3;
    size_t _wd = 5;
};

std::ostream& operator<<(std::ostream& os, const Rectangle& r);

