/*Description: This is the 'Card.cpp' file part of the overall program. This source file contains the 
implementation of the Card class declared in Card.h.It defines the constructors and getter functions for 
the Card class. The Card constructor calculates the card's value based on its rank and color. The printCard()
function returns a string representation of the card, e.g., "orange:4". Thank you for reading my code! :) */

#include "Card.h"

Card::Card() : rank(0), color(Color::purple), value(0) {}

Card::Card(int rank, Color color) : rank(rank), color(color) {
    if (color == Color::tiger) {
        value = 0; // Tiger card has no value
    } else if (color == Color::orange) {
        value = 2 * rank; // Orange card value is twice its rank
    } else {
        value = rank; // Purple card value is equal to its rank
    }
}

std::string Card::printCard() const {
    if (color == Color::tiger) {
        return "Tiger";
    } else {
        return (color == Color::orange ? "orange:" : "purple:") + std::to_string(rank);
    }
}

int Card::getRank() const {
    return rank;
}

Card::Color Card::getColor() const {
    return color;
}

int Card::getValue() const {
    return value;
}
