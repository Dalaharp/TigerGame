
/*Description: This is the 'Hand.cpp' file part of the overall program.This source file contains the 
implementation of the Hand class declared in Hand.h. It defines the constructors, printHand function, 
dealCard function, and getHandSize function for the Hand class. Thank you for reviewing my code!! :)*/

#include "Hand.h"

Hand::Hand() {}

Hand::Hand(Deck& deck, int N) {
    for (int i = 0; i < N; ++i) {
        hand.push_back(deck.drawCard());
    }
}

std::string Hand::printHand() const {
    std::string handStr;
    for (size_t i = 0; i < hand.size(); ++i) {
        handStr += "[" + std::to_string(i + 1) + "] " + hand[i].printCard() + " ";
    }
    return handStr;
}

Card Hand::dealCard(int num) {
    Card dealtCard = hand[num - 1];
    hand.erase(hand.begin() + num - 1);
    return dealtCard;
}

int Hand::getHandSize() const {
    return hand.size();
}
