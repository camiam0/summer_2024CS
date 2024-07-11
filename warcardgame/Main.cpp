#include <iostream>
#include <vector>

#include "deck.h"

void openingMessage() {

    std::cout << "War... war never changes...\n\n";

} // end of opening message

void showMenu() {

    std::cout << "Welcome to War, a program by camiam.\n";
    std::cout << "I will simulate the popular playing card game called War.\n";
    std::cout << "Please select from the following options:\n";
    std::cout << "\t1. View instructions.\n";
    std::cout << "\t2. Play against me.\n";
    std::cout << "\t3. Play against a friend.\n";
    std::cout << "\t4. Quit the program.\n";

} // end of menu

main() {

    bool menuflag = false;

    do {} while (!menuflag);

} // end of main

void instructions() {

    std::cout << "The goal is to be the first player to win all 52 cards.\n";
    std::cout << "The deck is shuffled and divided evenly, with each player receiving a 'stack' of 26 cards.\n";
    std::cout << "Each player draws a card at the same time and the player with the higher card\ntakes both cards and puts them on the bottom of his 'stack'.\n";
    std::cout << "If the cards drawn are the same rank, it is War.\n";
    std::cout << "Each player turns up one card face down and one card face up.\n";
    std::cout << "If the turned-up cards are again the same rank, each player starts another War,\n"; 
    std::cout << "repeating the initial steps until one player draws a higher card.\nThat player 'wins the War' and takes all cards drawn during the War.\n";
    std::cout << "The game ends when one player has won all the cards.\n";

} // end of instructions