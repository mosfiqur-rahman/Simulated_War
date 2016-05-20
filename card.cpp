#include "card.h"

card::card(Suit s, Rank r)
{
	myRank = r;
	mySuit = s;
}

Rank card::getRank() const
{
	return myRank;
}

Suit card::getSuit() const
{
	return mySuit;
}

ostream & operator<<(ostream& os, const card& c)
{
	map<Suit, string> suit_set = { { CLUBS, "C" }, { SPADES, "S" }, { DIAMONDS, "D" }, { HEARTS, "H" } };
	map<Rank, string> rank_set = { { TWO, "2" }, { THREE, "3" }, { FOUR, "4" }, {FIVE, "5"}, {SIX, "6"}, {SEVEN, "7"}, {EIGHT, "8"}, {NINE, "9"}, {TEN, "10"}, {JACK, "J"}, {QUEEN, "Q"}, {KING, "K"}, { ACE, "A" } };
	os << suit_set[c.getSuit()] << rank_set[c.getRank()] << " ";

	return os;
}

bool operator==(const card& lhs, const card& rhs)
{
	return lhs.getRank() == rhs.getRank();
}

bool operator<(const card & card_1, const card & card_2)
{
	return card_1.getRank() < card_2.getRank();
}

bool operator>(const card & card_1, const card & card_2)
{
	return card_1.getRank() > card_2.getRank();
}
