/*Description: This is the 'Deck.cpp' file part of the overall program. This source file contains the implementation 
of the Deck class declared in Deck.h. It defines the constructor, shuffle function, drawCard function, and getDeckSize 
function for the Deck class.The constructor populates the deck with 20 cards (10 purple and 10 orange) and shuffle 
randomly rearranges the cards. Thank you very much for reviewing my code!!!! :):):):):):):) */

#include "Deck.h"

Deck::Deck() {
    for (int rank = 1; rank <= 10; ++rank) {
        deck.push_back(Card(rank, Card::Color::purple));
        deck.push_back(Card(rank, Card::Color::orange));
    }
}

void Deck::shuffle() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::random_shuffle(deck.begin(), deck.end());
}

Card Deck::drawCard() {
    Card drawnCard = deck.back();
    deck.pop_back();
    return drawnCard;
}

int Deck::getDeckSize() const {
    return deck.size();
}

