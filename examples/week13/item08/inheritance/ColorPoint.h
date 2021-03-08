#pragma once

#include "Color.h"
#include "Point.h"

class ColorPoint : public Point {
  public:
    ColorPoint(int x, int y, Color color) 
      : _point{x, y}, _color{color} {
	}

	/**
	 * Returns the point of this color point.
	 */
	const Point& point() const override {
		return _point;
	}

  /**
	 * Returns the color of this color point.
	 */
	Color color() const {
		return _color;
	}


  private:
  const Point _point;
	const Color _color;

};


inline bool operator== (const ColorPoint& lhs, const ColorPoint& rhs)
{
  return lhs.point() == rhs.point() && lhs.color() == rhs.color();
}

inline bool operator!= (const ColorPoint& lhs, const ColorPoint& rhs)
{
  return !operator==(lhs,rhs);
}


// we need these other operators because we have claimed that a
// 'ColorPoint' IS-A 'Point'
//
// they need to be comparable, but this also introduces inconsistencies.
// see main()
inline bool operator== (const Point& lhs, const ColorPoint& rhs)
{
  return lhs.point() == rhs.point();
}

inline bool operator== (const ColorPoint& lhs, const Point& rhs)
{
  return operator==(rhs,lhs);
}



