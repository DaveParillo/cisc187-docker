#pragma once

#include <array>
#include <iostream>
#include <string>

namespace mesa {
  // If this were declared enum struct, nothing in this example changes...
  //
  enum class Direction { NORTH, SOUTH, EAST, WEST };


  /**
   * Allows the Direction class members to be printed with meaningful strings.
   * Example:
   *
   *     cout << "Direction is " << Direction::SOUTH << endl;
   */
  std::ostream& operator<<(std::ostream& os, const Direction& rhs);




  /**
   * Allows the Direction enum to be used ina range for loop
   * Example:
   *    for (const auto& d: directions) {
   *      // do something with the Direction d . . . 
   *    }
   */
  const std::array<Direction,4> directions = 
  {
    {
      Direction::NORTH,
      Direction::EAST,     
      Direction::SOUTH,    
      Direction::WEST     
    }
  };

}

