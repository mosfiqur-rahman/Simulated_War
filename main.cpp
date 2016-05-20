#include "deck.h"
#include "card.h"

deck gendeck()
{
	deck myCards;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			myCards.addCard(card((Suit)i, (Rank)j));
		}
	}
	return myCards;
}

int war(deck & player1, deck & player2)
{
	if (player1.size() < 2)
	{
		return 2;
	}
	if (player2.size() < 2)
	{
		return 1;
	}
	card p1_up = player1.dealCard();
	card p1_down = player1.dealCard();
	card p2_up = player2.dealCard();
	card p2_down = player2.dealCard();
	cout << "WAR!!" << endl << p1_up << " vs " << p2_up << endl;
	if (p1_up > p2_up)
	{
		player1.addCard(p1_up);
		player1.addCard(p1_down);
		player1.addCard(p2_up);
		player1.addCard(p2_down);
		return 1;
	}
	if (p1_up < p2_up)
	{
		player2.addCard(p1_up);
		player2.addCard(p1_down);
		player2.addCard(p2_up);
		player2.addCard(p2_down);
		return 2;
	}
	int res = war(player1, player2);
	if(res == 1)
	{
		player1.addCard(p2_up);
		player1.addCard(p2_down);
		player1.addCard(p1_up);
		player1.addCard(p1_down);
	}
	else
	{
		player2.addCard(p1_up);
		player2.addCard(p1_down);
		player2.addCard(p2_up);
		player2.addCard(p2_down);
	}
	return res;
}

int main()
{
	
	deck new_deck;
	new_deck = gendeck();
	new_deck.shuffle();

	deck player1 = new_deck.dealCards(26);
	deck player2 = new_deck.dealCards(26);

	while (player1.size() > 0 && player2.size() > 0)
	{
		card p1 = player1.dealCard();
		card p2 = player2.dealCard();
		cout << p1 << " vs " << p2 << endl;
		if (p1 > p2)
		{
			player1.addCard(p2);
			player1.addCard(p1);
		}
		else if (p1 < p2)
		{
			player2.addCard(p1);
			player2.addCard(p2);
		}
		else
		{
			int res = war(player1, player2);
			if (res == 1)
			{
				player1.addCard(p2);
				player1.addCard(p1);
			}
			else
			{
				player2.addCard(p1);
				player2.addCard(p2);
			}
		}
	}

	if (player1.size() == 0)
	{
		cout << "Player 2 Wins!" << endl;
	}
	else
	{
		cout << "Player 1 Wins!" << endl;
	}

	system("pause");
	return 0;
}
