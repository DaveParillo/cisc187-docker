#pragma once

#include <iostream>

// Tagged class - vastly inferior to a class hierarchy!
// from effective java, Item #20

// This file is an anti-pattern

enum figures { rectangle, circle };

class Figure {
  public:

    // Constructor for Circles
    Figure(double radius)
      : _shape{circle}, _radius{radius}, _ht{0}, _wd{0} {}

    // Constructor for Rectangles
    Figure(size_t height, size_t width)
      : _shape{rectangle}, _radius{0}, _ht{height}, _wd{width} {}

    double area()   const;
    size_t height() const { return _ht;};
    size_t width()  const { return _wd;};
    double radius() const { return _radius;};
    figures shape() const { return _shape;};

  private:
    const figures _shape;
    const double _radius;
    static constexpr double pi = 3.14159265358979;
    const size_t _ht;
    const size_t _wd;

};

std::ostream& operator<<(std::ostream& os, const Figure& rhs);

