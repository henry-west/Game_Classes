#ifndef GAME_H
#define GAME_H
class Game {
public:
    //constructor
    Game();
    //game classes
    void highLowGame();
    void ticTacToe();
    void cardGuess();
    virtual void play();
    //destructor
    //~Game();
};

#endif
