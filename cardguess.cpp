#include "game.h"
#include "cardguess.h"
#include <iostream>

using namespace std;
/**
 * CardGuess constructor
 * i/o: none
 */
CardGuess::CardGuess() {
    gameDeck.startDeck();
    gameDeck.shuffle();
    guessCardRank = 0;
    guessCardSuit = 'N';
    playerCard = new Card;
}
/* deal method
 * parameters, return, input: none
 * output: runs the actual game
 *
 * runs a single hand of the card guess game by
 * dealing a card off the deck
 */
void CardGuess::deal() {
    if (gameDeck.cardsLeft() >= 1) {
        //deal a card
        playerCard = gameDeck.dealTopCard();
        string response;
        cout << "Would you like a hint? ";
        cin >> response;
        if (response[0] == 'y' || response[0] == 'Y') {
            if (playerCard->getSuit() == 'D' || playerCard->getSuit() == 'H') {
                cout << "Suit -> red " << endl;
            }
            else {
                cout << "Suit -> black " << endl;
            }
            if (playerCard->getRank()%2 == 0 && playerCard->getRank() <= 10) {
                cout << "Rank -> even " << endl;
            }
            else if (playerCard->getRank()%2 != 0 && playerCard->getRank() <= 10) {
                cout << "Rank -> odd " << endl;
            }
            else {
                cout << "Rank -> a letter " << endl;
            }
        }
        cout << "Guess your card's rank (11-14 for J-A) and suit (D/H/C/S), separated by a space >>> " << endl;
        cin >> guessCardRank >> guessCardSuit;
        cout << "You guessed >>> " << guessCardRank << guessCardSuit << endl;
        cout << "\nYour card is >>> " << endl;
        playerCard->print();
    }
}
/* play method
 * parameters, return: none
 * output: a message to the user (cout) asking if they want to play another hand
 *      calls deal which displays the hand information and displayScore which
 *      prints the score message
 * input: a response from the user indicating whether to play again
 *
 * Runs the main game loop, dealing a hand as long as there are
 * cards left in the deck and user wants to keep playing
 */
void CardGuess::play() {
    while(gameDeck.cardsLeft()>=1)
    {
        cout << "Do you want to deal a hand? ";
        string response;
        cin >> response;
        if(response[0] == 'y' || response[0] == 'Y')
        {

            deal();
        }
        else
        {
            break;
        }
    }
}
//destructor
CardGuess::~CardGuess() {
    cout << "CM destructor";
    delete playerCard;
}


