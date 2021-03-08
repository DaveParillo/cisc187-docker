
#include "Direction.h"
#include <iostream>

using namespace mesa;

void show_direction(const Direction d);

int main() {
  Direction dir = Direction::WEST;
  std::cout << "Show one direction: " << std::endl;
  show_direction(dir);

  std::cout << "Loop through all directions: " << std::endl;
  for (const auto& d: directions) {
    show_direction(d);
  }
  return 0;
}


void show_direction(const Direction d) {
  std::cout << "Direction: " << d << std::endl;
}
