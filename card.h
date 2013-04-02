/* card.h: Specification of the Card class.
 *
 * author: Eric Manley
 * date:2/28/2013
 */

#ifndef CARD_H
#define CARD_H

/* Card class
 *
 * Represents a simple playing card with a rank value 2-10,J,Q,K, or A (assumes A is high)
 * and a suit which can be one of four characters 'S', 'C', 'H', or 'D' for the suits
 * Spades, Clubs, Hearts, and Diamonds respectively.
 */
class Card {
private:
    int rank;  //the card's numeric rank 2-14
    char suit; //char representing the card's suit
public:
    //constructors
    Card();    //default constructor creates 2D
    Card(int r, char s);

    //accessors
    int getRank() const;
    char getSuit() const;

    //mutators
    void setRank(int r);
    void setSuit(char s);

    void print() const;
    int compareTo(Card * other) const;
    ~Card();
};

#endif // CARD_H
