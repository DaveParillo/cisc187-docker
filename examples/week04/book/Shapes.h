#pragma once

#include <vector>
#include <stdexcept>

using std::vector;

struct Point {
    int x, y;
    Point(int xx, int yy) : x(xx), y(yy) { }
    Point() :x(0), y(0) { }
};

//------------------------------------------------------------------------------

inline bool operator==(Point a, Point b) { return a.x==b.x && a.y==b.y; } 

//------------------------------------------------------------------------------

inline bool operator!=(Point a, Point b) { return !(a==b); }



class Shape  {        // deals with color and style, and holds sequence of lines 
public:
    void draw() const;                 // deal with color and draw lines
    virtual void move(int dx, int dy); // move the shape +=dx and +=dy

    Point point(int i) const { return points[i]; } // read only access to points
    int number_of_points() const { return int(points.size()); }

    virtual ~Shape() { }
protected:
    Shape();    
    virtual void draw_lines() const;   // draw the appropriate lines
    void add(Point p);                 // add p to points
    void set_point(int i,Point p);     // points[i]=p;
private:
    vector<Point> points;              // not used by all shapes

    Shape(const Shape&);               // prevent copying
    Shape& operator=(const Shape&);
};


struct Rectangle : Shape {

    Rectangle(Point xy, int ww, int hh) : w(ww), h(hh)
    {
        add(xy);
        if (h<=0 || w<=0) throw std::runtime_error("Bad rectangle: non-positive side");
    }

    Rectangle(Point x, Point y) : w(y.x-x.x), h(y.y-x.y)
    {
        add(x);
        if (h<=0 || w<=0) throw std::runtime_error("Bad rectangle: non-positive width or height");
    }
    void draw_lines() const;

    int height() const { return h; }
    int width() const { return w; }
private:
    int h;    // height
    int w;    // width
};


struct Circle : Shape {
    Circle(Point p, int rr);    // center and radius

    void draw_lines() const;

    Point center() const ; 
    int radius() const { return r; }
    void set_radius(int rr) { r=rr; }
private:
    int r;
};


