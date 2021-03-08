#pragma once

#include <iostream>
#include <array>

enum class Rank {
  Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King
};

// Define an array of Rank to allow range-for looping
const std::array<Rank,13> ranks = 
{
  {
    Rank::Ace, Rank::Two, Rank::Three, Rank::Four, Rank::Five,    
    Rank::Six, Rank::Seven, Rank::Eight, Rank::Nine, Rank::Ten,    
    Rank::Jack, Rank::Queen, Rank::King     
  }
};

enum class Suit {
  Clubs, Diamonds, Hearts, Spades
};

// Define an array of Suit to allow range-for looping
const std::array<Suit,4> suits = 
{
  {
    Suit::Clubs, Suit::Diamonds, Suit::Hearts, Suit::Spades     
  }
};

struct Card {
  Rank rank;
  Suit suit;
};

std::ostream& operator<<(std::ostream& os, const Rank& rhs );
std::ostream& operator<<(std::ostream& os, const Suit& rhs );
std::ostream& operator<<(std::ostream& os, const Card& rhs );


