#include "Direction.h"

#include <iostream>
#include <string>

namespace mesa {

  std::ostream& operator<<(std::ostream& os, const Direction& rhs) {
    std::string dir;
    switch (rhs) {
      case Direction::NORTH: dir = "NORTH"; break;
      case Direction::EAST:  dir = "EAST";  break;
      case Direction::SOUTH: dir = "SOUTH"; break;
      case Direction::WEST:  dir = "WEST";  break;
    }
    return os << dir;
  }
}

