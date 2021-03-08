#pragma once
#include <iostream>
#include "Figure.h"

class Circle : public Figure {
  public:
    Circle()
      : _radius{1} {}

    Circle(double radius)
      : _radius{radius} {}

    double radius() const { return _radius;};
    double area()   const override;
  private:
    const double _radius;
    static constexpr double pi = 3.14159265358979;
};

std::ostream& operator<<(std::ostream& os, const Circle& rhs);


