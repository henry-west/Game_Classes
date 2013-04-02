/**
 * ttt.cpp: implementation of ttt.h
 * a tictactoe game made into a class
 * author: Jaxon Gittinger, Henry West
 *date: 3/27
 */

#include <iostream>
#include <string>
#include <cstdlib>

#include "game.h"
#include "ttt.h"

using namespace std;

TicTacToe::TicTacToe()
{
	pboard = new char[9]; //initializing the pointer to the array
}

void TicTacToe::play()
{
	//display initial board and game rules for user
	printInstructions();
	initializeBoard(); // fills the board with spaces


	//Let the user decide who goes first
	//Keep trying until they type correct input
	do
	{
		cout << "Do you want to go first? (y/n): ";
		cin >> response;
	} while (response != 'y' && response != 'n');

	if (response == 'y')
	{
		cout << "\nThen take the first move.  You will need it.\n";
		turn = 'X';
	}
	else
	{
		cout << "\nYour bravery will be your undoing... I will go first.\n";
		turn = 'O';
	}

	//The main game loop
	displayBoard();

	while (winner() == ' ') // while there is no winner yet
	{
		if (turn == 'X') //human's turn
		{
			humanMove();
			turn = 'O';
		}
		else
		{
			computerMove(); //computer's turn
			turn = 'X';
		}
		displayBoard();
	}

	//If we got here, it means the game is over
	//we'll announce the winner (or the tie)
	announceWinner();
}

void TicTacToe::printInstructions()
{
	cout << "Welcome to the ultimate man-machine showdown: Tic-Tac-Toe.\n";
	cout << "--where human brain is pit against silicon processor\n\n";

	cout << "Make your move known by entering a number, 0 - 8.  The number\n";
	cout << "corresponds to the desired board position, as illustrated:\n\n";

	cout << "       0 | 1 | 2\n";
	cout << "       ---------\n";
	cout << "       3 | 4 | 5\n";
	cout << "       ---------\n";
	cout << "       6 | 7 | 8\n\n";

	cout << "Prepare yourself, human.  The battle is about to begin.\n\n";
}

void TicTacToe::initializeBoard()
{
	for(int i = 0; i < 9; i++) //loop through all of the spaces on the board
	{
		*(pboard + i) = ' '; //updates the array position
	}
}

void TicTacToe::displayBoard()
{
	int a = 0; //since we can't simply do *(pboard++), this takes its place
	for(int i = 0; i < 3; i++)
	{
		int j;
		for(j = 0; j < 2; j++)
		{
			cout << " " << *(pboard + a) << " |";
			a = a + 1;
		}
		cout << " " << *(pboard + a) << endl;
		a = a + 1;
		if(i != 2)
		{
			cout << "-----------";
		}
		cout << endl;
	}
}

char TicTacToe::winner()
{
	winningPlayer = ' '; //if none of these following conditions are true, the game isn't over
	//these are all of the possible winning combinations for the human
	if(((*(pboard + 0) & *(pboard + 1) & *(pboard + 2)) == 'X') || ((*(pboard + 3) & *(pboard + 4) & *(pboard + 5)) == 'X') || ((*(pboard + 6) & *(pboard + 7) & *(pboard + 8)) == 'X') || ((*(pboard + 0) & *(pboard + 3) & *(pboard + 6)) == 'X') || ((*(pboard + 1) & *(pboard + 4) & *(pboard + 7)) == 'X') || ((*(pboard + 2) & *(pboard + 5) & *(pboard + 8)) == 'X') || ((*(pboard + 0) & *(pboard + 4) & *(pboard + 8)) == 'X') || ((*(pboard + 2) & *(pboard + 4) & *(pboard + 6)) == 'X'))
	{
		winningPlayer = 'X'; //the human is the winner
	}
	//these are all of the possible winning combinations for the computer

	else if(((*(pboard + 0) & *(pboard + 1) & *(pboard + 2)) == 'O') || ((*(pboard + 3) & *(pboard + 4) & *(pboard + 5)) == 'O') || ((*(pboard + 6) & *(pboard + 7) & *(pboard + 8)) == 'O') || ((*(pboard + 0) & *(pboard + 3) & *(pboard + 6)) == 'O') || ((*(pboard + 1) & *(pboard + 4) & *(pboard + 7)) == 'O') || ((*(pboard + 2) & *(pboard + 5) & *(pboard + 8)) == 'O') || ((*(pboard + 0) & *(pboard + 4) & *(pboard + 8)) == 'O') || ((*(pboard + 2) & *(pboard + 4) & *(pboard + 6)) == 'O'))
	{
		winningPlayer = 'O'; //the human is the winner
	}
	//if there hasn't been a winner, but the board is full, it's a tie
	else if(*(pboard + 0) != ' ' && *(pboard + 1) != ' ' && *(pboard + 2) != ' ' && *(pboard + 3) != ' ' && *(pboard + 4) != ' ' && *(pboard + 5) != ' ' && *(pboard + 6) != ' ' && *(pboard + 7) != ' ' && *(pboard + 8) != ' ')
	{
		winningPlayer = '-';
	}
	return winningPlayer;
}

bool TicTacToe::isLegal(int legal)
{
	//bool legalMove; //this variable will be true or false, depending on whether the move is legal
	if(*(pboard + legal) == ' ') //If the position on the board cooresponding to the requested move is open
	{
		legalMove = true; //then the move is legal
	}
	else //if that position on the board is already taken
	{
		legalMove = false; //then the move is illegal
	}
	return legalMove; //return either true or false
}

void TicTacToe::humanMove()
{
	legalMove = false; //this will determine whether or not the move is legal
	while(!legalMove) // while the move is legal
	{
		cout << "Make your move human. Not that it will matter..." << endl;
		cin >> hM; //save the human's move
		if(isLegal(hM) == true) //test if the move is legal
		{
			*(pboard + hM) = 'X'; //This is the space corresponding to
			//the generated move in the board array
			legalMove = true; //allows us to break out of the loop
		}
		else
		{
			cout << "This is not a legal move." << endl; //if it wasn't a legal move, notify the user and run the loop again
		}
	}
}

void TicTacToe::computerMove()
{
	bool legalMove = false; //variable to keep the loop running until a legal move is made
	while(legalMove == false) //runs until a legal move is made
	{
		int tryMove = rand()%9; //get's a random number between 0 and 8
		/*
		All of these if and else if statements represent all of the possible winning combinations for the computer, or winning combinations for the human.
		If one of these winning conditions is present on the board for the computer, it will take that move if it is legal.
		If none of these winning conditions are present on the board for the computer, but there is a winning condition present for the human, it will take that move if it is legal.
		If neither of these are present on the board, then the computer will make a random move. 
		*/
		if(((*(pboard + 0) & *(pboard + 1)) == 'O') && isLegal(tryMove = 2) == true)
		{
			tryMove = 2;
		}
		else if(((*(pboard + 0) & *(pboard + 2)) == 'O') && isLegal(tryMove = 1) == true)
		{
			tryMove = 1;
		}
		else if(((*(pboard + 1) & *(pboard + 2)) == 'O') && isLegal(tryMove = 0) == true)
		{
			tryMove = 0;
		}
		else if(((*(pboard + 3) & *(pboard + 4)) == 'O') && isLegal(tryMove = 5) == true)
		{
			tryMove = 5;
		}
		else if(((*(pboard + 3) & *(pboard + 5)) == 'O') && isLegal(tryMove = 4) == true)
		{
			tryMove = 4;
		}
		else if(((*(pboard + 4) & *(pboard + 5)) == 'O') && isLegal(tryMove = 3) == true)
		{
			tryMove = 3;
		}
		else if(((*(pboard + 6) & *(pboard + 7)) == 'O') && isLegal(tryMove = 8) == true)
		{
			tryMove = 8;
		}
		else if(((*(pboard + 6) & *(pboard + 8)) == 'O') && isLegal(tryMove = 7) == true)
		{
			tryMove = 7;
		}
		else if(((*(pboard + 7) & *(pboard + 8)) == 'O') && isLegal(tryMove = 6) == true)
		{
			tryMove = 6;
		}
		else if(((*(pboard + 0) & *(pboard + 3)) == 'O') && isLegal(tryMove = 6) == true)
		{
			tryMove = 6;
		}
		else if(((*(pboard + 0) & *(pboard + 6)) == 'O') && isLegal(tryMove = 3) == true)
		{
			tryMove = 3;
		}
		else if(((*(pboard + 3) & *(pboard + 6)) == 'O') && isLegal(tryMove = 0) == true)
		{
			tryMove = 0;
		}
		else if(((*(pboard + 1) & *(pboard + 4)) == 'O') && isLegal(tryMove = 7) == true)
		{
			tryMove = 7;
		}
		else if(((*(pboard + 1) & *(pboard + 7)) == 'O') && isLegal(tryMove = 4) == true)
		{
			tryMove = 4;
		}
		else if(((*(pboard + 4) & *(pboard + 7)) == 'O') && isLegal(tryMove = 1) == true)
		{
			tryMove = 1;
		}
		else if(((*(pboard + 2) & *(pboard + 5)) == 'O') && isLegal(tryMove = 8) == true)
		{
			tryMove = 8;
		}
		else if(((*(pboard + 2) & *(pboard + 8)) == 'O') && isLegal(tryMove = 5) == true)
		{
			tryMove = 5;
		}
		else if(((*(pboard + 5) & *(pboard + 8)) == 'O') && isLegal(tryMove = 2) == true)
		{
			tryMove = 2;
		}
		else if(((*(pboard + 0) & *(pboard + 4)) == 'O') && isLegal(tryMove = 8) == true)
		{
			tryMove = 8;
		}
		else if(((*(pboard + 0) & *(pboard + 8)) == 'O') && isLegal(tryMove = 4) == true)
		{
			tryMove = 4;
		}
		else if(((*(pboard + 4) & *(pboard + 8)) == 'O') && isLegal(tryMove = 0) == true)
		{
			tryMove = 0;
		}
		else if(((*(pboard + 2) & *(pboard + 4)) == 'O') && isLegal(tryMove = 6) == true)
		{
			tryMove = 6;
		}
		else if(((*(pboard + 2) & *(pboard + 6)) == 'O') && isLegal(tryMove = 4) == true)
		{
			tryMove = 4;
		}
		else if(((*(pboard + 4) & *(pboard + 6)) == 'O') && isLegal(tryMove = 2) == true)
		{
			tryMove = 2;
		}

		else //if there are no winning moves for the computer, check if there are for the human
		{
			if(((*(pboard + 0) & *(pboard + 1)) == 'X') && isLegal(tryMove = 2) == true)
			{
				tryMove = 2;
			}
			else if(((*(pboard + 0) & *(pboard + 2)) == 'X') && isLegal(tryMove = 1) == true)
			{
				tryMove = 1;
			}
			else if(((*(pboard + 1) & *(pboard + 2)) == 'X') && isLegal(tryMove = 0) == true)
			{
				tryMove = 0;
			}
			else if(((*(pboard + 3) & *(pboard + 4)) == 'X') && isLegal(tryMove = 5) == true)
			{
				tryMove = 5;
			}
			else if(((*(pboard + 3) & *(pboard + 5)) == 'X') && isLegal(tryMove = 4) == true)
			{
				tryMove = 4;
			}
			else if(((*(pboard + 4) & *(pboard + 5)) == 'X') && isLegal(tryMove = 3) == true)
			{
				tryMove = 3;
			}
			else if(((*(pboard + 6) & *(pboard + 7)) == 'X') && isLegal(tryMove = 8) == true)
			{
				tryMove = 8;
			}
			else if(((*(pboard + 6) & *(pboard + 8)) == 'X') && isLegal(tryMove = 7) == true)
			{
				tryMove = 7;
			}
			else if(((*(pboard + 7) & *(pboard + 8)) == 'X') && isLegal(tryMove = 6) == true)
			{
				tryMove = 6;
			}
			else if(((*(pboard + 0) & *(pboard + 3)) == 'X') && isLegal(tryMove = 6) == true)
			{
				tryMove = 6;
			}
			else if(((*(pboard + 0) & *(pboard + 6)) == 'X') && isLegal(tryMove = 3) == true)
			{
				tryMove = 3;
			}
			else if(((*(pboard + 3) & *(pboard + 6)) == 'X') && isLegal(tryMove = 0) == true)
			{
				tryMove = 0;
			}
			else if(((*(pboard + 1) & *(pboard + 4)) == 'X') && isLegal(tryMove = 7) == true)
			{
				tryMove = 7;
			}
			else if(((*(pboard + 1) & *(pboard + 7)) == 'X') && isLegal(tryMove = 4) == true)
			{
				tryMove = 4;
			}
			else if(((*(pboard + 4) & *(pboard + 7)) == 'X') && isLegal(tryMove = 1) == true)
			{
				tryMove = 1;
			}
			else if(((*(pboard + 2) & *(pboard + 5)) == 'X') && isLegal(tryMove = 8) == true)
			{
				tryMove = 8;
			}
			else if(((*(pboard + 2) & *(pboard + 8)) == 'X') && isLegal(tryMove = 5) == true)
			{
				tryMove = 5;
			}
			else if(((*(pboard + 5) & *(pboard + 8)) == 'X') && isLegal(tryMove = 2) == true)
			{
				tryMove = 2;
			}
			else if(((*(pboard + 0) & *(pboard + 4)) == 'X') && isLegal(tryMove = 8) == true)
			{
				tryMove = 8;
			}
			else if(((*(pboard + 0) & *(pboard + 8)) == 'X') && isLegal(tryMove = 4) == true)
			{
				tryMove = 4;
			}
			else if(((*(pboard + 4) & *(pboard + 8)) == 'X') && isLegal(tryMove = 0) == true)
			{
				tryMove = 0;
			}
			else if(((*(pboard + 2) & *(pboard + 4)) == 'X') && isLegal(tryMove = 6) == true)
			{
				tryMove = 6;
			}
			else if(((*(pboard + 2) & *(pboard + 6)) == 'X') && isLegal(tryMove = 4) == true)
			{
				tryMove = 4;
			}
			else if(((*(pboard + 4) & *(pboard + 6)) == 'X') && isLegal(tryMove = 2) == true)
			{
				tryMove = 2;
			}	
		}

		if( isLegal(tryMove) ) //If the move requested by the computer is legal

		{
			cout << "I shall take square number " << tryMove << endl;
			*(pboard + tryMove) = 'O'; //This is the space corresponding to
			//the generated move in the board array6

			legalMove = true; //allows us to break out of the loop
		}

		else //if there was no move requested by the computer
		{
			tryMove = rand()%9; //create a random move
			if( isLegal(tryMove) ) //if it's legal, make that move
			{
				cout << "I shall take square number " << tryMove << endl;
				*(pboard + tryMove) = 'O'; //This is the space corresponding to
				//the generated move in the board array
				legalMove = true; //allows us to break out of the loop
			}
		}
	}
}

void TicTacToe::announceWinner()
{
	if (winningPlayer == 'O')
	{
		cout << winningPlayer << "'s won!\n";
		cout << "As I predicted, human, I am triumphant once more -- proof\n";
		cout << "that computers are superior to humans in all regards.\n";
	}

	else if (winningPlayer == 'X')
	{
		cout << winningPlayer << "'s won!\n";
		cout << "No, no!  It cannot be!  Somehow you tricked me, human.\n";
		cout << "But never again!  I, the computer, so swear it!\n";
	}

	else if (winningPlayer == '-')
	{
		cout << "It's a tie.\n";
		cout << "You were most lucky, human, and somehow managed to tie me.\n";
		cout << "Celebrate... for this is the best you will ever achieve.\n";
	}
}

TicTacToe::~TicTacToe() 
{
    delete [] pboard; //deletes the board so that a memory leak doesn't occur
	cin >> wait; //so visual studio doesn't close the console immediately
}
