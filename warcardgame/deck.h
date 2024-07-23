#pragma once

#include <vector>
#include <string>

// constructing special card variables
enum Suit {Clubs, Spades, Hearts, Diamonds};
enum Rank {Two=2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace};

struct Card {

// initializing special card variables
Suit suit;
Rank rank;

Card(Suit s = Clubs, Rank r = Two) : suit(s), rank(r) {} // default constructor
std::string toString() const;

};

// abstract base class
class Drawable {

public:
    virtual Card draw() = 0; // pure virtual function
    virtual ~Drawable() = default; // virtual destructor
 
};

class Deck : public Drawable {

public:
    
    Deck();
    void shuffle();
    Card draw();

private:
    
    std::vector<Card> deck;

}; // end of deck class

class Player : public Drawable {

public:

    Card draw() override; // override keyword ensures this method overrides Drawable
    void addCard(const Card& card); // method to add cards to players deck
    size_t getDeckSize() const;

private:

    std::vector<Card> playerDeck;

};