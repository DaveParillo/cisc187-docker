#include <string>
#include <iostream>

// This is the thing we want to build
// There are many ways to make a pizza,
// but we want to create a structure to hide details about the pizza making
// The cook knows the process, but not the details
//
// This class is fairly wide open
// It doesn't impose any real restrictions.
// That is: theoretically, we can make ANY pizza

class Pizza {
  std::string dough_;
  std::string sauce_;
  std::string topping_;
public:
  void dough   (const std::string& dough_type)   { dough_ = dough_type; }
  void sauce   (const std::string& sauce_type)   { sauce_ = sauce_type; }
  void topping (const std::string& topping_type) { topping_ = topping_type; }
  void serve() const {
    std::cout << "Pizza with " << dough_ << " dough, " << sauce_ << " sauce, and "
      << topping_ << " topping. Yum!\n";
  }
};

