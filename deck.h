#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck {
public:
    Deck();
    Card * gameDeck;
    int cardIndex;
    
    void startDeck();
    void shuffle();
    Card* dealTopCard();
    
    int cardsLeft();
    ~Deck();

};

#endif
