
/*Description: This is the 'main.cpp' file part of the overall program. This is the main program file where 
the TigerGame is implemented and executed. It includes the necessary header files and defines the game's 
logic using the classes Card, Deck, Hand, and Player. The main program creates the deck, shuffles it, creates
two players, and plays five rounds of the game. It shows the game's progress, allows the human player to 
choose cards, determines the round winner, and displays the final game results. Thank you for reading my code! */

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

int main() {
    std::cout << "Welcome to TigerGame!" << std::endl;

    std::vector<int> humanScores, computerScores, roundsWonByHuman, roundsWonByComputer;

    char playAgain;

    do {
        // Ask the user for the number of cards each player should draw
        int numCards;
        do {
            std::cout << "Enter the number of cards each player should draw (max 10): ";
            std::cin >> numCards;
        } while (numCards <= 0 || numCards > 10);

        // Create a deck and shuffle it
        Deck deckOfCards;
        deckOfCards.shuffle();

        // Create players with the specified number of cards in their hand
        Player computer(deckOfCards, numCards);
        Player human(deckOfCards, numCards);

        // Keep track of game statistics
        int roundsWonByHumanTotal = 0;
        int roundsWonByComputerTotal = 0;

        // Play numCards rounds (based on the number of cards drawn)
        for (int round = 1; round <= numCards; ++round) {
            std::cout << "Round " << round << std::endl;
            std::cout << "-------" << std::endl;

            Card computerCard = computer.hand.dealCard(rand() % computer.hand.getHandSize() + 1);

            std::cout << "The computer plays: " << computerCard.printCard() << std::endl;
            std::cout << "Your hand: " << human.hand.printHand() << std::endl;

            int chosenCardNum;
            std::cout << "Which card do you want to play? ";
            std::cin >> chosenCardNum;

            Card humanCard;
            if (chosenCardNum == numCards + 1) { // If the player chose the Tiger card
                humanCard = Card(10, Card::Color::tiger);
            } else {
                humanCard = human.hand.dealCard(chosenCardNum);
            }

            // Determine the winner of the round (handling the Tiger card)
            if (computerCard.getColor() == Card::Color::tiger && humanCard.getColor() != Card::Color::tiger) {
                human.score += 20;
                std::cout << "You win this round! (Tiger card played)" << std::endl;
                ++roundsWonByHumanTotal;
            } else if (computerCard.getColor() != Card::Color::tiger && humanCard.getColor() == Card::Color::tiger) {
                computer.score += 20;
                std::cout << "Computer wins this round! (Tiger card played)" << std::endl;
                ++roundsWonByComputerTotal;
            } else if (computerCard.getValue() > humanCard.getValue()) {
                computer.score += computerCard.getValue() + humanCard.getValue();
                std::cout << "Computer wins this round!" << std::endl;
                ++roundsWonByComputerTotal;
            } else if (computerCard.getValue() < humanCard.getValue()) {
                human.score += computerCard.getValue() + humanCard.getValue();
                std::cout << "You win this round!" << std::endl;
                ++roundsWonByHumanTotal;
            } else {
                std::cout << "Tie!" << std::endl;
            }

            // Print current scores
            std::cout << "Current scores:" << std::endl;
            std::cout << "Human: " << human.score << std::endl;
            std::cout << "Computer: " << computer.score << std::endl;
            std::cout << std::endl;
        }

        // Store game statistics for this round
        humanScores.push_back(human.score);
        computerScores.push_back(computer.score);
        roundsWonByHuman.push_back(roundsWonByHumanTotal);
        roundsWonByComputer.push_back(roundsWonByComputerTotal);

        // Print final game results
        std::cout << "FINAL SCORE:" << std::endl;
        std::cout << "Human: " << human.score << std::endl;
        std::cout << "Computer: " << computer.score << std::endl;

        // Ask the player if they want to play again
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;

        if (playAgain == 'Y' || playAgain == 'y') {
            // Reset the deck and players for a new game
            deckOfCards.shuffle();
            computer.hand = Hand(deckOfCards, numCards);
            human.hand = Hand(deckOfCards, numCards);
            computer.score = 0;
            human.score = 0;
            // Continue with the game...
        } else {
            // Print a summary of all games
            std::cout << std::endl;
            std::cout << "Summary of all games:" << std::endl;
            for (size_t i = 0; i < humanScores.size(); ++i) {
                std::cout << "Game " << (i + 1) << ": " << std::endl;
                std::cout << "Human score: " << humanScores[i] << std::endl;
                std::cout << "Computer score: " << computerScores[i] << std::endl;
                std::cout << "Rounds won by Human: " << roundsWonByHuman[i] << std::endl;
                std::cout << "Rounds won by Computer: " << roundsWonByComputer[i] << std::endl;
                std::cout << std::endl;
            }
        }

    } while (playAgain == 'Y' || playAgain == 'y');

    return 0;
}
