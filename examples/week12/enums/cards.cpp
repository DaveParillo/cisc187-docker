#include "cards.h"

#include <iostream>
#include <array>
#include <vector>

// short, but not so great...
// a change in the order of the enum could break this,
// Assumes order: A,2,3,4,5,6,7,8,9,10,J,Q,K
// A more verbose switch would be better
std::ostream& operator<<(std::ostream& os, const Rank& rhs ) {
  if (rhs > Rank::Ace && rhs < Rank::Jack) {
    os << static_cast<int>(rhs);
  } else if (rhs == Rank::Ace) {
    os << "Ace";
  } else if (rhs == Rank::Jack) {
    os << "Jack";
  } else if (rhs == Rank::Queen) {
    os << "Queen";
  } else {
    os << "King";
  }

  return os;
}

std::ostream& operator<<(std::ostream& os, const Suit& rhs ) {
  switch(rhs) {
    case Suit::Clubs:    os << "Clubs"; break;
    case Suit::Diamonds: os << "Diamonds"; break;
    case Suit::Hearts:   os << "Hearts"; break;
    case Suit::Spades:   os << "Spades"; break;
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, const Card& rhs ) {
  return os << rhs.rank << " of " << rhs.suit;
}

