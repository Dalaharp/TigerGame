#ifndef DECK_H_
#define DECK_H_


/*Description: This is the 'Deck.h' file part of the overall program. This header file contains the declaration 
of the Deck class, which represents the deck of cards used in TigerGame. It defines the Deck class with a private 
member variable deck, which is a vector of Card objects. The class has functions for shuffling the deck, drawing a
 card from the deck, and getting the current deck size. Thank you for reading my code! :):):):) */

#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>

#include "Card.h"

class Deck {
public:
    Deck();

    void shuffle();
    Card drawCard();
    int getDeckSize() const;

private:
    std::vector<Card> deck;
};

#endif // DECK_H


