#pragma once

#include <algorithm>
#include <string>

static constexpr int min_weight = 1;

/** 
 * A class with simple encapsulation 
 */
class EvenBetterShipping {
  public:
    EvenBetterShipping() = default;
    EvenBetterShipping(int w, int d, std::string a) :
      weight_{std::max(min_weight, w)}, distance_{d}, address_{a}
    {}

    int  weight()          { return weight_; }
    void weight(int value) { 
      weight_ = std::max(min_weight, value);  // no upper limit on weight
    }


    int distance() { return distance_; }
    std::string address() {
      return address_;
    }
  private:
    int weight_ = 2;      // in pounds
    int distance_ = 100;    // in miles
    std::string address_ = "My mom's house";
};

