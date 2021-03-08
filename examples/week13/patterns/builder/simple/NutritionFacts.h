#pragma once

#include <iosfwd>

class NutritionFacts {
  private:
    // variables in need of initialization to make valid object
    const double serving_size_;  // mL
    const int servings_;         // per container
    const double calories_;      // Kcal
    const double fat_;           // g
    const double sodium_;        // mg
    const double carbs_;         // g
 

  public:
    // Only one simple constructor for mandatory parameters
    // - rest is handled by Builder
    NutritionFacts( const double serving_size, const int servings) 
      : serving_size_{serving_size}, servings_{servings},
      calories_{0}, fat_{0}, sodium_{0}, carbs_{0}
    {}

    // use this class to construct Nutritionfacts
    class Builder {
      private:
        friend NutritionFacts;
        double serving_size_ = 15;  // mL
        int servings_ = 10;         // per container
        double calories_ = 0;       // Kcal
        double fat_ = 0;            // g
        double sodium_ = 0;         // mg
        double carbs_ = 0;          // g

      public:
        Builder() = default;

        // create a Nutritionfacts object from a builder
        NutritionFacts build() {
          return NutritionFacts (*this);
        }

        Builder& serving_size(const double size) { 
          serving_size_ = size; 
          return *this;
        }
        Builder& servings(const int s) { 
          servings_ = s; 
          return *this;
        }
        Builder& calories(const double c) { 
          calories_ = c; 
          return *this;
        }
        Builder& fat(const double f) { 
          fat_ = f; 
          return *this;
        }
        Builder& sodium(const double s) { 
          sodium_ = s; 
          return *this;
        }
        Builder& carbohydrates(const double c) { 
          carbs_ = c; 
          return *this;
        }

    };

    explicit NutritionFacts(const Builder& builder)
      : serving_size_{builder.serving_size_}, 
      servings_{builder.servings_},
      calories_{builder.calories_}, 
      fat_{builder.fat_}, 
      sodium_{builder.sodium_}, 
      carbs_{builder.carbs_}
    {}

    double serving_size() const { return serving_size_; }
    int servings() const { return servings_; }
    double calories() const { return calories_; }
    double fat() const { return fat_; }
    double sodium() const { return sodium_; }
    double carbohydrates() const { return carbs_; }
};


std::ostream& operator<<(std::ostream& os, const NutritionFacts& rhs);


