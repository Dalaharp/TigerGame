#ifndef HAND_H_
#define HAND_H_

/*Description: This is the 'Hand.h' file part of the overall program. This header file contains the declaration
of the Hand class, which represents a player's hand of cards in TigerGame.It defines the Hand class with a private
member variable hand, which is a vector of Card objects. The class has a default constructor and a parameterized
constructor for dealing cards from the deck. It also includes functions for printing the hand, dealing a specific
card, and getting the current hand size. Thank you very much for reviewing my code!!!!! :):):):):) */

#include <vector>
#include <string>
#include <sstream>

#include "Deck.h"

class Hand {
public:
    Hand();
    Hand(Deck& deck, int N);

    std::string printHand() const;
    Card dealCard(int num);
    int getHandSize() const;

private:
    std::vector<Card> hand;
};

#endif // HAND_H


