// PokerHands.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string"
#include "fstream"
#include "iostream"
#include "vector"
using std::cout;
using std::endl;
using std::vector;

const int noLuck = 0;
const int luck = 1;
const int playerWon = 2;
const int tie = 3;

/* finding pairs cards */
vector<vector<int>> findPair(char cards[][2])
{
	int temp[5] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		if (cards[i][0] == 'A')
		{
			temp[i] = 14;
		}
		else if (cards[i][0] == 'K')
		{
			temp[i] = 13;
		}
		else if (cards[i][0] == 'B')
		{
			temp[i] = 12;
		}
		else if (cards[i][0] == 'J')
		{
			temp[i] = 11;
		}
		else if (cards[i][0] == 'T')
		{
			temp[i] = 10;
		}
		else
		{
			temp[i] = cards[i][0] - 48;
		}
	}
	vector<vector<int>> counter;
	for (int i = 0; i < 5; i++)
	{
		bool flag = true;;
		for (int j = 0; j < counter.size(); j++)
		{
			if (counter[j][0] == temp[i])
			{
				counter[j][1] += 1;
				flag = false;
			}
		}
		if (flag)
		{
			vector<int> newCard = { temp[i] , 1 };
			counter.push_back(newCard);
		}
	}
	return counter;
}

/* sort the cards with insertion sort */
vector<int> sortCard(char cards[5][2])
{
	vector<int>sortedCard;
	int temp = 0;
	for (int i = 0; i < 5; i++)
	{
		if (cards[i][0] == 'A')
		{
			sortedCard.push_back(14);
		}
		else if (cards[i][0] == 'K')
		{
			sortedCard.push_back(13);
		}
		else if (cards[i][0] == 'B')
		{
			sortedCard.push_back(12);
		}
		else if (cards[i][0] == 'J')
		{
			sortedCard.push_back(11);
		}
		else if (cards[i][0] == 'T')
		{
			sortedCard.push_back(10);
		}
		else
		{
			sortedCard.push_back(cards[i][0] - 48);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			if (sortedCard[j] > sortedCard[j + 1])
			{
				temp = sortedCard[j];
				sortedCard[j] = sortedCard[j + 1];
				sortedCard[j + 1] = temp;
			}
		}
	}
	return sortedCard;
}

int highCard(char whiteCards[5][2], char blackCards[5][2])
{
	vector<int> whiteCardsList = sortCard(whiteCards);
	vector<int> blackCardsList = sortCard(blackCards);
	for (int i = 4; i >= 0; i--)
	{
		if (whiteCardsList[i] > blackCardsList[i])
		{
			cout << "White Player Won the game with high card \n";
			return playerWon;
		}
		if (whiteCardsList[i] < blackCardsList[i])
		{
			cout << "black Player Won the game with high card \n";
			return playerWon;
		}
	}
	return tie;
}

int pair(char cards[5][2])
{
	vector<vector<int>> counter = findPair(cards);
	for (int i = 0; i < counter.size(); i++)
	{
		if (counter[i][1] == 2)
		{
			return counter[i][0];
		}
		return noLuck;
	}
}

int twoPairs(char cards[5][2])
{
	vector<vector<int>> counter = findPair(cards);
	for (int i = 0; i < counter.size(); i++)
	{
		if (counter[i][1] == 2)
		{
			int highCard = counter[i][0];
			for (int j = 0; j < counter.size() && j != i; j++)
			{
				if (counter[j][1] == 2)
				{
					if (highCard > counter[j][0])
					{
						return (highCard * 100 + counter[j][0]);
					}
					return (counter[j][0] * 100 + highCard);
				}
			}
		}
	}
	return noLuck;
}

int threeOfAKind(char cards[5][2])
{
	vector<vector<int>> counter = findPair(cards);
	for (int i = 0; i < counter.size(); i++)
	{
		if (counter[i][1] == 3)
		{
			return counter[i][0];
		}
	}
	return noLuck;
}

int straight(char cards[5][2])
{
	int min = 0;
	int max = 0;
	for (int i = 0; i < 5; i++)
	{
		if (cards[i][0] == 'A')
		{
			max = 14;
		}
		else if (cards[i][0] == 'K')
		{
			if (max < 13)
			{
				max = 13;
			}
		}
		else if (cards[i][0] == 'Q')
		{
			if (max < 12)
			{
				max = 12;
			}
		}
		else if (cards[i][0] == 'J')
		{
			if (max < 11)
			{
				max = 11;
			}
		}
		else if (cards[i][0] == 'T')
		{
			if (max < 10)
			{
				max = 10;
			}
			if (min > 10)
			{
				min = 10;
			}
		}
		else
		{
			int temp = cards[i][0] - 48;
			if (temp > max)
			{
				max = temp;
			}
			if (temp < min)
			{
				min = temp;
			}
		}
	}
	if (max - min == 4)
	{
		return luck;
	}
	return noLuck;
}

int flush(char cards[5][2])
{
	for (int i = 1; i < 5; i++)
	{
		if (cards[i][1] != cards[0][1])
		{
			return noLuck;
		}
	}
	return luck;
}

int fullHouse(char cards[5][2])
{
	vector<vector<int>> counter = findPair(cards);
	for (int i = 0; i < counter.size(); i++)
	{
		if (counter[i][1] == 2)
		{
			for (int j = 0; j < counter.size(); j++)
			{
				if (counter[j][1] == 3)
				{
					return counter[j][0];
				}
			}
		}
	}
	return noLuck;
}

int fourOfAKind(char cards[5][2])
{
	vector<vector<int>> counter = findPair(cards);
	for (int i = 0; i < counter.size(); i++)
	{
		if (counter[i][1] == 4)
		{
			return counter[i][0];
		}
	}
	return noLuck;
}

int straightFlush(char cards[5][2])
{
	if (flush(cards) == noLuck)
	{
		return noLuck;
	}
	if (straight(cards) == noLuck)
	{
		return noLuck;
	}
	return luck;
}

int findWinner(int whiteFlag, int blackFlag)
{
	if (whiteFlag > blackFlag)
	{
		cout << "White player wins!!!\n";
		return playerWon;
	}
	else if (blackFlag > whiteFlag)
	{
		cout << "Black player wins!!!\n";
		return playerWon;
	}
	else if (blackFlag == luck && whiteFlag == luck)
	{
		return tie;
	}
	return noLuck;
}

bool wineCheck(char whiteCards[5][2], char blackCards[5][2])
{
	/* straight flush win check */
	int whiteFlag = straightFlush(whiteCards);
	int blackFlag = straightFlush(blackCards);
	int result = findWinner(whiteFlag, blackFlag);
	if (result != noLuck)
	{
		if (result == tie)
		{
			result = highCard(whiteCards, blackCards);
			if (result == playerWon)
			{
				cout << "won in straight flush with high card\n";
				return true;
			}
		}
		else if (result == playerWon)
		{
			cout << "won in straight flush!\n";
			return true;
		}
	}

	/* four of a kind win check */
	whiteFlag = fourOfAKind(whiteCards);
	blackFlag = fourOfAKind(blackCards);
	result = findWinner(whiteFlag, blackFlag);
	if (result != noLuck)
	{
		cout << "won in four of a kind!\n";
		return true;
	}

	/* full house win check */
	whiteFlag = fullHouse(whiteCards);
	blackFlag = fullHouse(blackCards);
	result = findWinner(whiteFlag, blackFlag);
	if (result != noLuck)
	{
		cout << "won in full house!!!\n";
		return true;
	}

	/* flush win check */
	whiteFlag = flush(whiteCards);
	blackFlag = flush(blackCards);
	result = findWinner(whiteFlag, blackFlag);
	if (result != noLuck)
	{
		if (result == tie)
		{
			result = highCard(whiteCards, blackCards);
			if (result == playerWon)
			{
				cout << "won in flush with high card\n";
				return true;
			}
		}
		else if (result == playerWon)
		{
			cout << "won in flush!\n";
			return true;
		}
	}

	/* strait win check */
	whiteFlag = straight(whiteCards);
	blackFlag = straight(blackCards);
	result = findWinner(whiteFlag, blackFlag);
	if (result != noLuck)
	{
		if (result == tie)
		{
			result = highCard(whiteCards, blackCards);
			if (result == playerWon)
			{
				cout << "won in straight with high card\n";
				return true;
			}
		}
		else if (result == playerWon)
		{
			cout << "won in straight!\n";
			return true;
		}
	}

	/* three of a kind win check */
	whiteFlag = threeOfAKind(whiteCards);
	blackFlag = threeOfAKind(blackCards);
	result = findWinner(whiteFlag, blackFlag);
	if (result != noLuck)
	{
		cout << "won in three of a kind!!!\n";
		return true;
	}

	/* two pair win check */
	whiteFlag = twoPairs(whiteCards);
	blackFlag = twoPairs(blackCards);
	if (whiteFlag == noLuck || blackFlag == noLuck)
	{
		result = findWinner(whiteFlag, blackFlag);
		if (result == playerWon)
		{
			cout << "won in tow pairs!\n";
			return true;
		}
	}
	else if ((whiteFlag / 100) > (blackFlag / 100))
	{
		cout << "white player won the game with higher two pair cards\n";
		return true;
	}
	else if ((whiteFlag / 100) < (blackFlag / 100))
	{
		cout << "black player won the game with higher two pair cards\n";
		return true;
	}
	else if ((whiteFlag % 100) > (blackFlag % 100))
	{
		cout << "white player won the game with second higher two pair cards\n";
		return true;
	}
	else if ((whiteFlag % 100) < (blackFlag % 100))
	{
		cout << "black player won the game with second higher two pair cards\n";
		return true;
	}
	else
	{
		vector<vector<int>> whiteCardFlag = findPair(whiteCards);
		vector < vector<int> >blackCardFlag = findPair(blackCards);
		for (int i = 0; i < whiteCardFlag.size(); i++)
		{
			if (whiteCardFlag[i][1] == 1)
			{
				whiteFlag = whiteCardFlag[i][0];
				break;
			}
		}
		for (int i = 0; i < blackCardFlag.size(); i++)
		{
			if (blackCardFlag[i][1] == 1)
			{
				blackFlag = blackCardFlag[i][0];
				break;
			}
		}
		if (whiteFlag > blackFlag)
		{
			cout << "white player won the game in tow pairs with highest remaining card \n";
		}
		else if (blackFlag > whiteFlag)
		{
			cout << "black player won the game in tow pairs with highest remaining card \n";

		}
	}

	/* one pair win check */
	whiteFlag = pair(whiteCards);
	blackFlag = pair(blackCards);
	if (whiteFlag == noLuck || blackFlag == noLuck)
	{
		result = findWinner(whiteFlag, blackFlag);
		if (result == playerWon)
		{
			cout << "won in one pair cards!\n";
			return true;
		}
	}
	else if (whiteFlag > blackFlag)
	{
		cout << "white player won the game with higher pair cards\n";
		return true;
	}
	else if (whiteFlag < blackFlag)
	{
		cout << "black player won the game with higher pair cards\n";
		return true;
	}
	else
	{
		vector<vector<int>> whiteCardsList = findPair(whiteCards);
		vector<vector<int>> blackCardsList = findPair(blackCards);
		for (int i = 0; i < whiteCardsList.size(); i++)
		{
			if (whiteCardsList[i][1] == 2)
			{
				whiteCardsList[i][0] = 0;
			}
			if (blackCardsList[i][1] == 2)
			{
				blackCardsList[i][0] = 0;
			}
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4 - i; j++)
			{
				if (whiteCardsList[j][0] > whiteCardsList[j + 1][0])
				{
					whiteFlag = whiteCardsList[j][0];
					whiteCardsList[j][0] = whiteCardsList[j + 1][0];
					whiteCardsList[j + 1][0] = whiteFlag;
				}
				if (blackCardsList[j][0] > blackCardsList[j + 1][0])
				{
					blackFlag = blackCardsList[j][0];
					blackCardsList[j][0] = blackCardsList[j + 1][0];
					blackCardsList[j + 1][0] = blackFlag;
				}
			}
		}
		for (int i = 4; i > 1; i--)
		{
			if (whiteCardsList[i][0] > blackCardsList[i][0])
			{
				cout << "white player won the game with higher card in on pair \n";
				return true;
			}
			else if (whiteCardsList[i][0] < blackCardsList[i][0])
			{
				cout << "black player won the game with higher card in on pair \n";
				return true;
			}

		}
	}

	/* high card win check */
	result = highCard(whiteCards, blackCards);
	if (result == playerWon)
	{
		return true;
	}
	else
	{
		cout << "game tied!!! no player won the game in any condition!!!\n";
	}
	return false;
}

int main()
{
	std::ifstream input;
	input.open("input.txt");
	if (!input.is_open())
	{
		cout << "Can't open the input file!!!" << endl;
		return 0;
	}
	char whiteCards[5][2];
	char blackCards[5][2];
	std::string temp;
	while (!input.eof())
	{
		std::getline(input, temp);
		int x = 0, y = 0;
		for (int i = 0; i < 14; i++)
		{
			if (temp[i] != ' ')
			{
				blackCards[x][y++] = temp[i];
				if (y == 2)
				{
					y = 0;
					x += 1;
					if (x == 5)
					{
						x = 0;
						y = 0;
						break;
					}
				}
			}
		}
		for (int i = 14; i < 29; i++)
		{
			if (temp[i] != ' ')
			{
				whiteCards[x][y++] = temp[i];
				if (y == 2)
				{
					y = 0;
					x += 1;
					if (x == 5)
					{
						break;
					}
				}
			}
		}
		cout << "\n\n" << temp<<endl;
		wineCheck(whiteCards, blackCards);
	}
}

