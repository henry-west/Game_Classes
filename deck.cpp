#include <iostream>
#include "deck.h"

using namespace std;
//constructor
Deck::Deck() 
{
    cardIndex = 0;
}
/**
 * input, output, param: none
 * return: none
 * Deck initializer (NOT constructor), creates deck full of cards
 */
void Deck::startDeck()
{
    gameDeck = new Card[52];
    for (int i = 1; i < 15; i++) {
        for (int j = 1; j < 5; j++) {
            //makes looping through suits possible
            switch (j) {
                case 1:
                    (gameDeck + i*j - 1)->setSuit('S');
                    break;
                case 2:
                    (gameDeck + i*j - 1)->setSuit('D');
                    break;
                case 3:
                    (gameDeck + i*j - 1)->setSuit('H');
                    break;
                case 4:
                    (gameDeck + i*j - 1)->setSuit('C');
                    break;
                default:
                    return;
            }
            (gameDeck + i*j - 1)->setRank(i);
        }
    }
}
/**
 * shuffle funct
 * i/o, param, return: none
 * shuffles deck - takes second half of deck and
 * puts each element between two elements of the first half,
 * may improve later
 */
void Deck::shuffle()
{
    Card temp_card;
    for (int i = 0; i < 26; i++) {
        if (i%2 == 1) {
            temp_card = *(gameDeck + i);
            *(gameDeck + i) = *(gameDeck + i + 26);
            *(gameDeck + i + 26) = temp_card;
        }
    }
}
/**
 * deal funct
 * i/o: none
 * return: pointer to the top card of the deck,
 * sends top card of deck to a player's hand
 */
Card* Deck::dealTopCard()
{
    cardIndex++;
    if (cardIndex == 54) {
        return 0;
    }
    else {
        return (gameDeck + cardIndex  - 1);
    }
}
/**
 * card counter
 * i/o: none
 * return: number of cards in the deck minus the card index
 * gives user the number of cards left in the deck
 */
int Deck::cardsLeft()
{
    return 52 - cardIndex;
}
//destructor
Deck::~Deck() {
    
    delete [] gameDeck;
    cout << "Deck destructor" << endl;
}
