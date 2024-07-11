#include <iostream>
#include <random>
#include <ctime>

#include "deck.h"

Deck::Deck() {

    for(int suit = Clubs; suit <= Diamonds; suit++) {

        for(int rank = Two; rank <= Ace; rank++) {

            Card card = {static_cast<Suit>(suit), static_cast<Rank>(rank)};
            cards.push_back(card);

        }

    }
    shuffle();
} // end of Deck

void Deck::shuffle() {

    std::random_device rd; // obtains 'rd' seed from hardware
    std::mt19937 g(rd()); // Mersenne Twister pseudo-rng engine 'mt19937' seeded with 'rd', named 'g'
    std::shuffle(cards.begin(), cards.end(), g); // Shuffle the 'cards' vector with 'g'

} // end of shuffle

Card Deck::draw() {

    Card card = cards.back(); // get last card in vector
    cards.pop_back(); // remove that card
    
    return card; // "draws" card

} // end of draw