#pragma once

#include <cstddef>
#include <iostream>
#include "Figure.h"

class Rectangle : public Figure {
  public:
    Rectangle()
      : _ht{1}, _wd{1} {}

    Rectangle(std::size_t height, std::size_t width)
      : _ht{height}, _wd{width} {}

    std::size_t height() const { return _ht;};
    std::size_t width()  const { return _wd;};
    double area()   const override;
  private:
    const std::size_t _ht;
    const std::size_t _wd;
};

std::ostream& operator<<(std::ostream& os, const Rectangle& r);


