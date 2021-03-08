#pragma once

#include "Pizza.h"
#include <memory>

// from cpprefernce.com
// C++11 does not define std::make_unique
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

// "Abstract Builder"
// Since PizzaBuilder contains unimplemented functions (pure virtuals)
// we can't create an instance of a Pizza Builder
// we can only instantiate types that implement all of the 
// PizzaBuilder interfaces (dough, sauce, & topping)

class PizzaBuilder {
public:
  virtual ~PizzaBuilder() = default;

  Pizza* pizza() {
    return pizza_.release();
  }
  void createNewPizzaProduct() {
    pizza_ = make_unique<Pizza>();
  }
  virtual void buildDough() = 0;
  virtual void buildSauce() = 0;
  virtual void buildTopping() = 0;
protected:
  std::unique_ptr<Pizza> pizza_;
};

//
// Specific builders for pizza types on our menu
//
// They have o data of their own, but know what to do to a pizza
// to make a pizza of this type
//
// These classes are also virtual in case we want to make 
// a variation on a pizza - say deep dish Hawaiian

struct HawaiianPizzaBuilder : public PizzaBuilder {
  virtual ~HawaiianPizzaBuilder() = default;
  virtual void buildDough()   { pizza_->dough("cross"); }
  virtual void buildSauce()   { pizza_->sauce("mild"); }
  virtual void buildTopping() { pizza_->topping("ham+pineapple"); }
};

struct DeepDishHawaiianPizzaBuilder : public HawaiianPizzaBuilder {
  virtual ~DeepDishHawaiianPizzaBuilder() = default;
  virtual void buildDough()   { pizza_->dough("deep dish"); }
};

struct SpicyPizzaBuilder : public PizzaBuilder {
  virtual ~SpicyPizzaBuilder() = default;
  virtual void buildDough()   { pizza_->dough("thin crust"); }
  virtual void buildSauce()   { pizza_->sauce("hot"); }
  virtual void buildTopping() { pizza_->topping("pepperoni+salami"); }
};

