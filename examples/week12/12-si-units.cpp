#include "mks.h"

#include <iostream>

// A small program demonstrating using the mks units defined in mks.h.
// 
// If you want to play more, consider looking at boost's unit implementaion:
//
// http://www.boost.org/doc/libs/1_65_1/doc/html/boost_units/Quick_Start.html

int main() {
  auto distance = Quantity<Meter>{100};  // 100 meters
  auto time = Quantity<Second>{20.5};
  auto speed = distance / time;

  std::cout << "Speed: " << speed << '\n';

  // 3 different ways to express the same thing...
  // verbose
  Speed sp1 = Quantity<Unit<1,0,0>> (100)/ Quantity<Unit<0,0,1>> (9.8); 

  // shorter
  Speed sp2 = Quantity<Meter> (100)/ Quantity<Second> (9.8);

  // using literal overload
  Speed sp3 = 100.0_m/9.8_s;

  std::cout << "Speeds: " << sp1 << '\t' << sp2 << '\t' << sp3 << '\t' << '\n';
}


