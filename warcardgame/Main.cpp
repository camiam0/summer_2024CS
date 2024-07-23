#include <iostream>
#include <random>
#include <ctime>
#include <vector>

#include "deck.h"

using namespace std;

// Function prototypes
void showMenu();
void instructions();
void dealCards(Deck& deck, Player& player1Deck, Player& player2Deck);
void War();
void handleWar(Player& player1Deck, Player& player2Deck, std::vector<Card>& warPile);

void openingMessage() {

    std::cout << "War... war never changes...\n\n";
    std::cout << "Welcome to War, a program by camiam.\n";
    std::cout << "I will simulate the popular playing card game called War.\n";

} // end of opening message

int main() {

    bool menuFlag = false;
    int menuSelect = 0;

    openingMessage();

    do {

        showMenu();
        cin >> menuSelect;
        
        switch (menuSelect) 
        {

            case 1:
                
                std::cout << "How to play War:\n";
                instructions();
                menuSelect = 0;
                break;
            
            case 2:

                std::cout << "TO WAR!!!\n";
                War();
                menuSelect = 0;
                break;

            case 3:

                std::cout << "Goodbye!\n";
                menuFlag = true;
                break;

            default:

                std::cout << "Invalid selection, please try again.\n";
                break;

        } // end of menu switch case
    } while (!menuFlag);

    return 0;

} // end of main

// menu for user navigation
void showMenu() {

    std::cout << "Please select from the following options:\n";
    std::cout << "\t1. Press 1 then enter to view instructions.\n";
    std::cout << "\t2. Press 2 then enter to play a game.\n";
    std::cout << "\t3. Press 3 then enter to quit the program.\n";

} // end of show menu

// instructions on how to play War
void instructions() {

    std::cout << "The full deck of 52 cards is shuffled and divided evenly, with each player receiving their own 'deck' of 26 cards.\n";
    std::cout << "Each player draws a card at the same time and the player with the higher ranked card\ntakes both cards and puts them on the bottom of his 'deck'.\n";
    std::cout << "If the cards drawn are the same rank, it is War.\n";
    std::cout << "Each player draws three cards face down and one card face up.\n";
    std::cout << "If the face up cards are again the same rank, each player starts another War,\n"; 
    std::cout << "repeating the initial steps until one player draws a higher ranked card.\nThat player 'wins the War' and takes all cards drawn during the War.\n";
    std::cout << "The game ends when one player has won all the cards.\n";

} // end of instructions

void dealCards(Deck& deck, Player& player1Deck, Player& player2Deck) {

    for (int i = 0; i < 26; i++) {

        player1Deck.addCard(deck.draw());
        player2Deck.addCard(deck.draw());

    }
} // end of deal cards

void War() {
    
    // Initialize decks
    Deck deck;
    Player player1Deck;
    Player player2Deck;
    std::cout << "War table is set.\n";

    // win counters
    int player1Win = 0;
    int player2Win = 0;

    dealCards(deck, player1Deck, player2Deck);
    std::cout << "Cards are dealt.\n";

    while (player1Deck.getDeckSize() > 0 && player2Deck.getDeckSize() > 0) {
        
        // draw cards
        std::cout << "Drawing cards...\n";
        Card player1Card = player1Deck.draw();
        Card player2Card = player2Deck.draw();
        std::cout << "Player one's card: " + player1Card.toString() + "\tPlayer two's card: " + player2Card.toString() + "\n";

        // compare drawn cards
        if (player1Card.rank > player2Card.rank) {
            
            // player 1 wins the round
            player1Deck.addCard(player1Card);
            player1Deck.addCard(player2Card);
            std::cout << "Player one wins the battle!\n";

        } else if (player1Card.rank < player2Card.rank) {
            
            // player 2 wins the round
            player2Deck.addCard(player1Card);
            player2Deck.addCard(player2Card);
            std::cout << "Player two wins the battle!\n";

        } else {
            
            // war condition: both cards have the same rank
            std::vector<Card> warPile = {player1Card, player2Card};
            std::cout << "Tie.\n";

            // handle war
            handleWar(player1Deck, player2Deck, warPile);

        } // end of if else game logic

        // check for a winner
        if (player1Deck.getDeckSize() == 0) {
            
            std::cout << "Player one is out of troops!\n";
            player2Win = true;
            break;

        } else if (player2Deck.getDeckSize() == 0) {
            
            std::cout << "Player two is out of troops!\n";
            player1Win = true;
            break;
        
        } // end of if else winner check
    } // end of game while loop

    // if else for player win msg
    if (player1Win) {std::cout << "Player one wins the War.\n";
    
    } else if (player2Win) {std::cout << "Player two wins the War.\n";}
} // end of War function

void handleWar(Player& player1Deck, Player& player2Deck, std::vector<Card>& warPile) {
    
    std::cout << "Sending reinforcements:\n";

    // Ensure both players have enough cards to continue the war
    while (player1Deck.getDeckSize() >= 4 && player2Deck.getDeckSize() >= 4) {
        
        // Each player draws 3 cards face down and 1 card face up
        for (int i = 0; i < 3; ++i) {
            
            warPile.push_back(player1Deck.draw());
            warPile.push_back(player2Deck.draw());
        
        }

        Card player1WarCard = player1Deck.draw();
        Card player2WarCard = player2Deck.draw();
        warPile.push_back(player1WarCard);
        warPile.push_back(player2WarCard);

        std::cout << "Reinforcements have arrived.\n";
        std::cout << "Player one's war card: " + player1WarCard.toString() + "\tPlayer two's war card: " + player2WarCard.toString() + "\n";

        // Compare the war cards
        if (player1WarCard.rank > player2WarCard.rank) {
            
            std::cout << "Player one wins the war!\n";
            for (const Card& c : warPile) {
                
                player1Deck.addCard(c);
           
            }
            
            warPile.clear();
            break;
        
        } else if (player1WarCard.rank < player2WarCard.rank) {
            
            std::cout << "Player two wins the war!\n";
            for (const Card& c : warPile) {
                
                player2Deck.addCard(c);
            
            }
            
            warPile.clear();
            break;
        
        } else {
            
            std::cout << "Tie again!\n";
            // Continue the war with additional cards
        
        } // end of tie logic
    } // end of war while loop

    // Handle cases where a player can't continue the war
    if (player1Deck.getDeckSize() < 4 || player2Deck.getDeckSize() < 4) {
        
        if (player1Deck.getDeckSize() < 4) {
            
            std::cout << "Player one is out of troops!\n";
            for (const Card& c : warPile) {
                
                player2Deck.addCard(c);
            
            }
        
        } else if (player2Deck.getDeckSize() < 4) {
            
            std::cout << "Player two is out of troops!\n";
            for (const Card& c : warPile) {
                
                player1Deck.addCard(c);
            
            }
        }
        
        warPile.clear();
    
    } // end of case where player cant continue
} // end of handleWar