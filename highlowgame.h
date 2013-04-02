/* highlowgame.h: Specification of the HighLowGame class
 *
 * author: Eric Manley
 * date:2/28/2013
 */

#ifndef HIGHLOWGAME_H
#define HIGHLOWGAME_H

#include "deck.h"
#include "card.h"
#include "game.h"

/* HighLowGame class
 *
 * Represents the High-Low Card game in which a human player plays against
 * the computer. Cards are successively dealt from a deck to each player
 * with the holder of the higher ranked card winning that hand. This class
 * runs the game loop and keeps track of player scores.
 */
class HighLowGame : public Game {
    int playerScore;  //the human player's score
    int computerScore;//the computer player's score
    Deck gameDeck;    //the deck of cards
    Card * playerCard;
    Card * computerCard;
public:

    HighLowGame(); //constructor
    void displayScore(); //prints the score to cout
    void dealHand(); //runs one hand of the game
    void play(); //runs the game loop
    ~HighLowGame();
    

};

#endif // HIGHLOWGAME_H
