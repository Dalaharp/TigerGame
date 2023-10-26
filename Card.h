#ifndef CARD_H
#define CARD_H

/*Description: This is the 'Card.h' file part of the overall program. This header file contains the 
declaration of the Card class, which represents a single card in the TigerGame. It defines the Card class 
with private member variables rank, color, and value. It also includes an enumeration Color for the card 
colors, i.e., purple and orange. The class has a default constructor, a parameterized constructor, and getter
 functions for retrieving card information. Thank you so much for reviewing my code!!! :):):):) */

#include <string>

class Card {
public:
    enum Color { purple, orange, tiger };

    Card();
    Card(int rank, Color color);
    std::string printCard() const;
    int getRank() const;
    Color getColor() const;
    int getValue() const;

private:
    int rank;
    Color color;
    int value;
};

#endif // CARD_H
