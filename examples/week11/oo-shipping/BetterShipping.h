#pragma once

#include <string>

/** 
 * A class with simple encapsulation 
 */
class BetterShipping {
  public:
    int weight()   { return weight_; }
    void weight(int value) { 
      weight_ = value; 
    }

    int distance() { return distance_; }
    std::string address() {
      return address_;
    }
    // other mutators ommitted . . .
  private:
    int weight_;      // in pounds
    int distance_;    // in miles
    std::string address_;
};

