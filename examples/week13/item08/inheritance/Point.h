#pragma once

class Point {
  public:
    Point(): _x{0}, _y{0} { }
    Point(int x, int y): _x{x}, _y{y} { }
    int x() const { return _x;}
    int y() const { return _y;}
    virtual const Point& point() const{ return *this;};
  private:
    const int _x;
    const int _y;
};

inline bool operator== (const Point& lhs, const Point& rhs)
{
  return lhs.x() == rhs.x() && lhs.y() == rhs.y();
}

