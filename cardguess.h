#ifndef CardGuess_H
#define CardGuess_H

#include "game.h"
#include "deck.h"
#include "card.h"

class CardGuess : Game {
    int guessCardRank;
    char guessCardSuit;
    Deck gameDeck;
    Card * playerCard;


public:
    CardGuess(); //constructor
    void deal(); //deals a card
    void play(); //game loop
    ~CardGuess();
};

#endif // CardGuess_H
