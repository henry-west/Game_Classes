/**
 * game.cpp: implementation of the game class,
 * which after a menu in main.cpp, redirects the
 * user to a chosen game
 * author: Henry West/Jaxon Gittinger
 * date: 3/27/2013
 */
#include "game.h"
#include "highlowgame.h"
#include "cardguess.h"
#include "ttt.h"
#include <iostream>

using namespace std;

Game::Game() {
}
void Game::highLowGame() {
    HighLowGame * g = new HighLowGame;
    g->play();
}
void Game::ticTacToe() {
    TicTacToe * g = new TicTacToe;
    g->play();
}
void Game::cardGuess() {
    CardGuess * g = new CardGuess;
    g->play();
}

void Game::play() {
}
/*
Game::~Game() {
    cout << "This is the game destructor" << endl;
}
*/
