#include<stdio.h>

// This horriible little program is seen often enough to warrant including as an example.
//
// This is an anti-pattern: how *not* to implement polymorphism in C
//
// It's a C version of a 'tagged class' - an equally bad OO version of the same anti-pattern.

const int PI = 3.14159265358979323846;

struct Shape {
  int type;       // is this Shape a Circle or a Rectangle?
  float area;
  float length;
};

struct Circle {
  struct Shape circle;
  float radius;
};

struct Rectangle {
  struct Shape rect;
  float height;
  float width;
};

//for circle
float area(float);
float length(float);
//for rectangle
float r_area(float, float);
float r_length(float, float);
void process(struct Shape s);


int main() {
  struct Shape shape;

  printf("\nEnter the type of shape (0 = circle, 1 = rectangle) : ");
  scanf("%d", &shape.type);

  // shape.type = 0;
  process(shape);

  return (0);
}

// Produce circle results
void process(struct Shape s) {
  struct Circle c;
  struct Rectangle r;

  if (s.type == 0) {

    c.circle = s;

    printf("\nEnter the radius of Circle : ");
    scanf("%f", &c.radius);

    c.circle.area = area(c.radius);
    printf("\nArea of Circle : %.2f\n", c.circle.area);

    c.circle.length = length(c.radius);
    printf("\nCircumfrence of Circle : %.2f\n", c.circle.length);
  } else {
    r.rect = s;

    printf("\nEnter the height of Rectangle : ");
    scanf("%f", &r.height);

    printf("\nEnter the width of Rectangle : ");
    scanf("%f", &r.width);

    r.rect.area = r_area(r.height, r.width);
    printf("\nArea of Rectangle : %.2f\n", r.rect.area);

    r.rect.length = r_length(r.height, r.width);
    printf("\nPerimeter of Rectangle : %.2f\n", r.rect.length);
  }

}

// area of a circle
float area (float radius) {
  return (float)PI * radius * radius;
}

// circumfrence of a circle
float length (float radius) {
  return (float)PI * 2.0f * radius;
}


// area of a rectangle: height * width
float r_area (float h, float w) {
  return h * w;
}

// perimeter of a rectangle
float r_length (float height, float width) {
  return 2.0f * height + 2.0f * width;
}




