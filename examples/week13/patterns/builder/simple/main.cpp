#include "NutritionFacts.h"

#include <iostream>

int main() {
  NutritionFacts cake = {75, 8};
  NutritionFacts soda = NutritionFacts::Builder()
                        .serving_size(368).servings(1)
                        .carbohydrates(40).calories(150).sodium(15);

  NutritionFacts::Builder b;
  b.serving_size(28.4).servings(1);
  b.fat(10).sodium(2).calories(150).carbohydrates(15);
  auto chips = b.build();

  std::cout << "Cake:\t" << cake << "\n";
  std::cout << "Soda:\t" << soda << "\n";
  std::cout << "Chips:\t" << chips << "\n";

  return 0;
}

