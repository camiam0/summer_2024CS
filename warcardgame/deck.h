#pragma once

#include "card.h"
#include <vector>

class Deck {

public:
    Deck();
    void shuffle();
    Card draw();

private:
    std::vector<Card> cards;

}; // end of deck header