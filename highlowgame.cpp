/* highlowgame.cpp: Implementation for the HighLowGame class specified in highlowgame.h
 *
 * author: Eric Manley
 * date:2/28/2013
 */

#include <iostream>

#include "game.h"
#include "highlowgame.h"

using namespace std;


/* HighLowGame constructor
 * parameters, return, input, output: none
 *
 * Initializes scores and shuffles the deck
 */
HighLowGame::HighLowGame() {
    playerScore = 0;
    computerScore = 0;
    //gameDeck.print(); //for debugging
    gameDeck.startDeck();
    gameDeck.shuffle();
    //gameDeck.print(); //for debugging
    computerCard = new Card;
    playerCard = new Card;
}


/* displayScore method
 * parameters, return, input: none
 * output: prints a message with the game scores to cout
 */
void HighLowGame::displayScore() {
    cout << endl << "Player Score: " << playerScore << endl;
    cout << "Computer Score: " << computerScore << endl;
    cout << "Cards left in the deck: " << gameDeck.cardsLeft() << endl << endl;
}

/* dealHand method
 * parameters, return, input: none
 * output: displays the dealt cards and the result of the hand to cout
 *
 * runs a single hand of the high-low card game by
 * dealing each player a card off the deck and incrementing
 * the score for the winning player
 */
void HighLowGame::dealHand() {
    //only play if there are at least two cards in the deck
    if(gameDeck.cardsLeft() >= 2)
    {
        //deal a card to each player
        playerCard = gameDeck.dealTopCard();
        computerCard = gameDeck.dealTopCard();

        //display the hands
        cout << "\nPlayer's Card: ";
        playerCard->print();
        cout << "\nComputer's Card: ";
        computerCard->print();

        //determine winner and update score
        if(playerCard->compareTo(computerCard) < 0)
        {
            cout << "\nComputer wins this hand." << endl;
            computerScore++;
        }
        else if(playerCard->compareTo(computerCard) > 0)
        {
            cout << "\nPlayer wins this hand." << endl;
            playerScore++;
        }
        else
        {
            cout << "\nThis hand is a draw." << endl;
        }
    }
    else
        cout << "The deck is empty." << endl;

}

/* play method
 * parameters, return: none
 * output: a message to the user (cout) asking if they want to play another hand
 *      calls dealHand which displays the hand information and displayScore which
 *      prints the score message
 * input: a response from the user indicating whether to play again
 *
 * Runs the main game loop, dealing a hand as long as there are
 * cards left in the deck and user wants to keep playing
 */
void HighLowGame::play() {

    while(gameDeck.cardsLeft()>=2)
    {
        displayScore();
        cout << "Do you want to deal a hand? ";
        string response;
        cin >> response;
        if(response[0] == 'y' || response[0] == 'Y')
        {

            dealHand();
        }
        else
        {
            break;
        }
    }
    displayScore();
}
HighLowGame::~HighLowGame() {
    cout << "HLG destrctor" << endl;
}
