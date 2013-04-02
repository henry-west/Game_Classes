/* main.cpp: driver program for the card game classes
 *description: a series of games, connected through pointers and classes
 * using an abstract class to direct flow from one class to the next
 * author: Henry West, Jaxon Gittinger
 * date: 3/27/2013
 * proposed points: 50/50
 */

#include <iostream>

#include "ttt.h"
#include "highlowgame.h"
#include "game.h"

using namespace std;

/* main function
 * input, output, parameters: none
 * return: system exit code
 *
 * entry point of the program, simply creates
 * an instance of the high-low game and plays it
 */
int main() {
    int response = -1;
    Game * myGame;
    while (response != 0)
    {
        cout << "Press 1 to play High Low" << endl;
        cout << "Press 2 to play Tic-Tac-Toe" << endl;
        cout << "Press 3 to play Card Guess" << endl;
        cout << "Press 0 to quit" << endl;
        cin >> response;
        switch (response) {
            case 1:
                myGame->highLowGame();
                cout << "here";
                break;
            case 2:
                myGame->ticTacToe();
                break;
            case 3:
                myGame->cardGuess();
                break;
            default:
                return 0;
        }
        delete myGame;
    }
}

