#include "PizzaBuilder.h"
//
// Notice the cook (the Director), only knows 1 thing:
// - the steps it takes to make a pizza
//
//  The cook doesn't even have to have any pizza objects
//
class Cook {
  public:
    Cook() = default;
    void servePizza() {
      pizzaBuilder->pizza()->serve();
    }
    void makePizza(PizzaBuilder* pb)
    {
      pizzaBuilder = pb;
      pizzaBuilder->createNewPizzaProduct();
      pizzaBuilder->buildDough();
      pizzaBuilder->buildSauce();
      pizzaBuilder->buildTopping();
    }
  private:
    PizzaBuilder* pizzaBuilder;
};


