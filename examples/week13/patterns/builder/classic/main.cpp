#include "Cook.h"
#include "PizzaBuilder.h"

int main() {
  Cook cook;
  HawaiianPizzaBuilder         hawaiian;
  DeepDishHawaiianPizzaBuilder dd_hawaiian;
  SpicyPizzaBuilder            spicy;

  cook.makePizza(&hawaiian);
  cook.servePizza();

  cook.makePizza(&spicy);
  cook.servePizza();

  cook.makePizza(&dd_hawaiian);
  cook.servePizza();

  return 0;
}

