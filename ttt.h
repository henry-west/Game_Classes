/**
 * ttt.h: declaration a tictactoe game made into a class
 * author: Jaxon Gittinger, Henry West
 *date: 3/27
 */

#ifndef TTT_H
#define TTT_H

#include "game.h"

class TicTacToe : public Game {

public:
    char * pboard;
    int wait;
    char response;
    char turn;
    int hM;
    bool legalMove;
    char winningPlayer;
    int legal;
    int tryMove;
public:
    TicTacToe();
    void printInstructions();
    void initializeBoard();
    void displayBoard();
    char winner();
    bool isLegal(int legal);
    void humanMove();
    void computerMove();
    void announceWinner();
    void play();
    ~TicTacToe();
};

#endif //TTT_H
