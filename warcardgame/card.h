#pragma once

// constructing special card variables
enum Suit {Clubs, Spades, Hearts, Diamonds};
enum Rank {Two=2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

struct Card {

// initializing special card variables
Suit suit;
Rank rank;

void print() const;

}; // end of card header