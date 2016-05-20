#ifndef _CARD_
#define _CARD_


// Card H File by Mosfiqur Rahman
// Drexel University 2016


#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
enum Suit { CLUBS, SPADES, DIAMONDS, HEARTS };
class card
{
	public:	
		
	//Standard poker card set
	card(Suit s, Rank r);
	Rank getRank()	const;
	Suit getSuit()  const;

	private:

	Rank myRank;
	Suit mySuit;
};
//Output Operator
ostream & operator<<(ostream& os, const card& c);
//Comparison Operator
bool operator==(const card& lhs, const card& rhs);
//Comparison Operator
bool operator<(const card & my_rank, const card & my_suit);
//Comparison Operator
bool operator>(const card & my_rank, const card & my_suit);

#endif
