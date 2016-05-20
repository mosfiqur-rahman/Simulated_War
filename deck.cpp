// Main File by Mosfiqur Rahman
// Drexel University 2016

#include "deck.h"

deck::deck(){}
//Deck Shuffle


int myrandom(int i) 
{ 
	return std::rand() % i; 
}
void deck::shuffle()
{
	random_shuffle(myCards.begin(), myCards.end(), myrandom);
}

//Number of cards left
size_t deck::size() const
{
    return myCards.size();
}

//Deals card
card deck::dealCard()
{
	//assert(size() > 0);
	card temp = myCards[0];
	myCards.pop_front();
	return temp;
}

deck deck::dealCards(int n)
{
	deck cards;
	for (int i = 0; i < n; i++)
	{
		cards.addCard(myCards.front());
		myCards.pop_front();
	}
	return cards;
}

void deck::addCard(card c)
{
	myCards.push_back(c);
}
