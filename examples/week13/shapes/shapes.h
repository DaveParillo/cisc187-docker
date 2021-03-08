#pragma once

#include <iostream>

class enum Color {RED, ORANGE, YELLOW, 
				  GREEN, BLUE, INDIGO, VIOLET,
				  WHITE, BLACK};

class shape {
  public:
    virtual ~shape() = default;
    virtual void   draw() const = 0;
    virtual void   erase();
    virtual void   move();
    virtual void   color (Color new_color);
    virtual Color  color()  const;
};


class circle: public shape {
	double radius = 1;
  public:
    void   draw()  const override;
    void   erase() override;
};


class rectangle: public shape {
	double ht = 1;
	double wd = 1;
  public:
    void   draw()  const override;
    void   erase() override;
};


class triangle: public shape {
	double height = 1;
	double base   = 1;
  public:
    void   draw()  const override;
    void   erase() override;
};


