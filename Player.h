#ifndef PLAYER_H
#define PLAYER_H

/*Description: This is the 'Player.h' file part of the overall program. This header file contains the 
declaration of the Player class, which represents a player in TigerGame. It includes the Hand class as 
a member variable to represent the player's hand of cards. The class also has a public member variable 
score to keep track of the player's score. It includes a default constructor and a parameterized constructor
for creating player instances. Thank you very much for reviewing my code!!!!! :):):):):):):):):):) */

#include "Hand.h"

class Player {
public:
    Player() : hand(), score(0) {}
    Player(Deck& deck, int N) : hand(deck, N), score(0) {}

    Hand hand;
    int score;
};

#endif // PLAYER_H

