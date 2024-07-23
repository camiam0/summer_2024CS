#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>
#include <string>

#include "deck.h"

// allows printing of cards to screen
std::string Card::toString() const {

    const char* suit_names[] = {"Clubs", "Spades", "Hearts", "Diamonds"};
    const char* rank_names[] = {"", "", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};

    // construct and return as a string
    return std::string(rank_names[rank]) + " of " + suit_names[suit];

} // end of toString

Deck::Deck() {

    // nested for loop will iterate over all combinations of suit and rank
    for(int suit = Clubs; suit <= Diamonds; suit++) {

        for(int rank = Two; rank <= Ace; rank++) {

            Card card = {static_cast<Suit>(suit), static_cast<Rank>(rank)}; // card objects are initialized
            deck.push_back(card); // cards are added to deck

        }
    }
    
    shuffle();

} // end of Deck

void Deck::shuffle() {

    std::random_device rd; // obtains 'rd' seed from hardware
    std::mt19937 g(rd()); // Mersenne Twister pseudo-rng engine 'mt19937' seeded with 'rd', named 'g'
    std::shuffle(deck.begin(), deck.end(), g); // Shuffle the 'cards' vector with 'g'

} // end of shuffle

Card Deck::draw() {

    // handle empty deck
    if (deck.empty()) {

        return Card();

    }

    Card card = deck.back(); // get last card in vector
    deck.pop_back(); // remove that card
    
    return card; // "draws" card

} // end of draw

Card Player::draw() {

    // handle empty deck
    if (playerDeck.empty()) {

        return Card();

    }

    Card card = playerDeck.back();
    playerDeck.pop_back();
    
    return card;

}

// adds card to a player deck
void Player::addCard(const Card& card) {playerDeck.push_back(card);}

// gets a players deck size
size_t Player::getDeckSize() const {return playerDeck.size();}