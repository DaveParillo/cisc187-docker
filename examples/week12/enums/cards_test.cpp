#include "cards.h"

#include <iostream>
#include <vector>

int main() {
  std::vector<Card> deck;
  for (const auto& s: suits) {
    for (const auto& r: ranks) {
      deck.push_back(Card{r,s});
    }
  }
  for(const auto& c : deck ) {
    std::cout << c << '\n';
  }
  return 0;
}

