#ifndef _DECK_
#define _DECK_


// Deck H File by Mosfiqur Rahman
// Drexel University 2016

#include "card.h"
#include <deque>
#include <algorithm>
#include <ctime>
#include <cassert>

class deck
{
	public:	
		
	deck();	

	void shuffle();
	card dealCard();
	deck dealCards(int n);
	size_t size() const;
	void addCard(card c);


	private:

	deque<card> myCards;
};

#endif
