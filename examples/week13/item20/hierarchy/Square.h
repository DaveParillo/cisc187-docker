#pragma once

#include <iostream>
#include "Figure.h"
#include "Rectangle.h"

class Square : public Figure {
  public:
    Square (size_t side)
      : rect {side, side} {}

    size_t side() const { return rect.height(); }
    double area() const override;

  private:
    const Rectangle rect;
};

std::ostream& operator<<(std::ostream& os, const Square& rhs);


