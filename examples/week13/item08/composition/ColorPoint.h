#pragma once

#include "Color.h"
#include "Point.h"

class ColorPoint {
  public:
    ColorPoint(Point point, Color color) 
      : _point{point}, _color{color} {
	}

	/**
	 * Returns the point-view of this color point.
	 */
	Point as_point() const {
		return _point;
	}

  /**
	 * Returns the color of this point.
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
  return lhs.as_point() == rhs.as_point() && lhs.color() == rhs.color();
}

inline bool operator!= (const ColorPoint& lhs, const ColorPoint& rhs)
{
  return !operator==(lhs,rhs);
}

