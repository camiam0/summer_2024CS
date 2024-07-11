#include <iostream>
#include "card.h"

void Card::print() const {

    const char* suit_names[] = {"Clubs", "Spades", "Hearts", "Diamonds"};
    const char* rank_names[] = {"", "", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

    std::cout << rank_names[rank] << "of" << suit_names[suit];

} // end of print