/* card.cpp: Implementation for the Card class specified in card.h .
 *
 * author: Eric Manley
 * date:2/28/2013
 */

#include "card.h"
#include <iostream>

using namespace std;

/* default Card constructor
 * parameters, return, input, output: none
 *
 * by default, we just create a 2 of diamonds
 */
Card::Card()
{
    rank = 2;
    suit = 'D';
}

/* Card constructor
 * parameters: an int for the rank, and a char for the suit
 * return, input, output: none
 *
 * by default, we just create a 2 of diamonds
 */
Card::Card(int r, char s)
{
    rank = r;
    suit = s;
}

/* getRank method
 * return: the card's rank
 * parameters, input, output: none
 *
 * accessor method for rank
 */
int Card::getRank() const
{
    return rank;
}

/* getSuit method
 * return: the card's suit
 * parameters, input, output: none
 *
 * accessor method for suit
 */
char Card::getSuit() const
{
    return suit;
}

/* setRank method
 * parameters: the card's new rank
 * return, input, output: none
 *
 * mutator method for rank
 */
void Card::setRank(int r)
{
    if (r >= 2 && r <= 14) {
        rank = r;
    }
}

/* setSuit method
 * parameters: the card's new suit
 * return, input, output: none
 *
 * mutator method for suit
 */
void Card::setSuit(char s)
{
    if (s == 'S' || s == 'C' || s == 'H' || s == 'D') {
        suit = s;
    }
}

/* print method
 * parameters, return, input, output: none
 *
 * outputs a desciption of the card to cout
 */
void Card::print() const
{
    //first, convert the rank to a letter
    //if it is a face card
    if(rank == 11)
        cout << "J";
    else if(rank == 12)
        cout << "Q";
    else if(rank == 13)
        cout << "K";
    else if(rank == 14)
        cout << "A";
    else
        cout << rank; //otherwise, just print the rank

    cout << suit; //just print the char representing the suit
}

/* compareTo method
 * parameters: other, a pointer to another Card
 * return: -1 if this Card has lower rank than other
 *          0 if this Card has the same rank as other
 *          1 if this Card has greater rank than other
 *
 * used to compare the relative rank of two Cards
 */
int Card::compareTo(Card * other) const
{
    if(rank < other->rank)
        return -1;
    else if(rank == other->rank)
        return 0;
    else
        return 1;
}
Card::~Card() {
    cout << "This is the card destructor " << endl;
}
