#include <iostream>
#include <cmath>

// volume of a cube
double volume( const double a ) {
  return a * a * a;
}

// volume of a cylinder
double volume( const double r, const double h ) {
  return M_PI * r * r * h;
}

// volume of a cuboid
double volume( const double a, const double b, const double c ) {
  return a * b * c;
}

int main() {
  std::cout << "volume of a 2 x 2 x 2 cube: " << volume(2.0) << '\n';
  std::cout << "volume of a cylinder, radius 2, height 2: " << volume(2.0, 2.0) << '\n';
  std::cout << "volume of a 2 x 3 x 4 cuboid: " << volume(2.0, 3.0, 4.0) << '\n';
  return 0;
}
