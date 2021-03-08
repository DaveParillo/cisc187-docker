#include "NutritionFacts.h"

#include <iostream>


std::ostream& operator<<(std::ostream& os, const NutritionFacts& rhs) {
  return os << "Serving size: " << rhs.serving_size()
            << "\tServings: " << rhs.servings()
            << "\tCal: " << rhs.calories()
            << "\tFat: " << rhs.fat()
            << "\tSodium: " << rhs.sodium()
            << "\tCarbs: " << rhs.carbohydrates();

}


