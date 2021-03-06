// CheckTheCheck.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fstream"
#include "iostream"
#include "cstring"
#include "string"
using std::cout;
const int boardSize = 8;

bool checkRook(char board[boardSize][boardSize], int x, int y, char rook, char queen)
{
	for (int i = x; i < boardSize; i++)
	{
		if (board[i][y] == rook || board[i][y] == queen)
		{
			return true;
		}
		else if (board[i][y] == '.')
		{
			continue;
		}
		else
		{
			if (isupper(board[i][y] && isupper(board[x][y])))
			{
				break;
			}
			else if (islower(board[i][y]) && islower(board[x][y]))
			{
				break;
			}
		}
	}
	for (int i = x; i >= 0; i--)
	{
		if (board[i][y] == rook || board[i][y] == queen)
		{
			return true;
		}
		else if (board[i][y] == '.')
		{
			continue;
		}
		else
		{
			if (isupper(board[i][y] && isupper(board[x][y])))
			{
				break;
			}
			else if (islower(board[i][y]) && islower(board[x][y]))
			{
				break;
			}
		}
	}
	for (int i = y; i < boardSize; i++)
	{
		if (board[x][i] == rook || board[x][i] == queen)
		{
			return true;
		}
		else if (board[x][i] == '.')
		{
			continue;
		}
		else
		{
			if (isupper(board[x][i] && isupper(board[x][y])))
			{
				break;
			}
			else if (islower(board[x][i]) && islower(board[x][y]))
			{
				break;
			}
		}
	}
	for (int i = y; i >= 0; i--)
	{
		if (board[x][i] == rook || board[x][i] == queen)
		{
			return true;
		}
		else if (board[x][i] == '.')
		{
			continue;
		}
		else
		{
			if (isupper(board[x][i] && isupper(board[x][i])))
			{
				break;
			}
			else if (islower(board[x][i]) && islower(board[x][i]))
			{
				break;
			}
		}
	}
	return false;
}

bool checkBishop(char board[boardSize][boardSize], int x, int y, char bishop, char queen)
{
	for (int i = x-1, j= y-1; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j] == bishop || board[i][j] == queen)
		{
			return true;
		}
		else if (board[i][j] == '.')
		{
			continue;
		}
		else {
			break;
		}
	}

	for (int i = x-1, j = y+1; i >= 0 && j < boardSize; i--, j++)
	{
		if (board[i][j] == bishop || board[i][j] == queen)
		{
			return true;
		}
		else if (board[i][j] == '.')
		{
			continue;
		}
		else {
			break;
		}
	}

	for (int i = x+1, j = y-1; j >= 0 && i < boardSize; j--, i++)
	{
		if (board[i][j] == bishop || board[i][j] == queen)
		{
			return true;
		}
		else if (board[i][j] == '.')
		{
			continue;
		}
		else {
			break;
		}
	}

	for (int i = x+1, j = y+1; i < boardSize && j < boardSize; i++, j++)
	{
		if (board[i][j] == bishop || board[i][j] == queen)
		{
			return true;
		}
		else if (board[i][j] == '.')
		{
			continue;
		}
		else {
			break;
		}
	}
	return false;
}

bool checkKnight(char board[boardSize][boardSize], int x, int y, char knight)
{
	if (x - 2 >= 0 && y - 1 >= 0)
	{
		if (board[x - 2][y - 1] == knight)
		{
			return true;
		}
	}
	if (x - 2 >= 0 && y + 1 < boardSize)
	{
		if (board[x - 2][y + 1] == knight)
		{
			return true;
		}
	}

	if (x + 2 < boardSize && y - 1 >= 0)
	{
		if (board[x + 2][y - 1] == knight)
		{
			return true;
		}
	}

	if (x + 2 < boardSize && y + 1 < boardSize)
	{
		if (board[x + 2][y + 1] == knight)
		{
			return true;
		}
	}

	if (x - 1 >= 0 && y - 2 >= 0)
	{
		if (board[x - 1][y - 2] == knight)
		{
			return true;
		}
	}
	if (x + 1 < boardSize && y - 2 >= 0)
	{
		if (board[x + 1][y - 2] == knight)
		{
			return true;
		}
	}

	if (x - 1 >= 0 && y + 2 < boardSize)
	{
		if (board[x - 1][y + 2] == knight)
		{
			return true;
		}
	}

	if (x + 1 < boardSize && y + 2 < boardSize)
	{
		if (board[x + 1][y + 2] == knight)
		{
			return true;
		}
	}
	return false;
}

bool checkPawn(char board[boardSize][boardSize], int x, int y, char pawn)
{
	if (islower(pawn))
	{
		if (board[x + 1][y - 1] == pawn)
		{
			return true;
		}
		if (board[x + 1][y + 1] == pawn)
		{
			return true;
		}
	}
	if (isupper(pawn))
	{
		if (board[x - 1][y - 1] == pawn)
		{
			return true;
		}
		if (board[x - 1][y + 1] == pawn)
		{
			return true;
		}
	}
	return false;
}

bool kingCheck(char board[boardSize][boardSize], int x, int y, bool isWhite)
{
	char pawn = isWhite ? 'p' : 'P';
	char rook = isWhite ? 'r' : 'R';
	char bishop = isWhite ? 'b' : 'B';
	char knight = isWhite ? 'n' : 'N';
	char queen = isWhite ? 'q' : 'Q';
	char king = isWhite ? 'K' : 'k';

	if (checkRook(board, x, y, rook, queen))
	{
		return true;
	}
	if (checkBishop(board, x, y, bishop, queen))
	{
		return true;
	}
	if (checkKnight(board, x, y, knight))
	{
		return true;
	}
	if (checkPawn(board, x, y, pawn))
	{
		return true;
	}
	return false;
}

bool checkBoard(char board[boardSize][boardSize])
{
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			if (board[i][j] == 'K')
			{
				if (kingCheck(board, i, j, true))
				{
					cout << "White King is in check!\n";
					return true;
				}
			}
			else if (board[i][j] == 'k')
			{
				if (kingCheck(board, i, j, false))
				{
					cout << "Black King is in check!\n";
					return true;
				}
			}
		}
	}
	cout << "No king is in check!";
	return false;
}

int main()
{
	std::ifstream inputStream;
	inputStream.open("input.txt");
	if (!inputStream.is_open())
	{
		cout << "cant open input.txt !!";
		exit(0);
	}
	char board[boardSize][boardSize];
	int counterGame = 1;
	while (!inputStream.eof())
	{
		std::string temp;
		bool endOfInput = true;
		for (int i = 0; i < boardSize; i++)
		{
			getline(inputStream, temp);
			for (int j = 0; j < boardSize; j++)
			{
				board[i][j] = temp[j];
				if (temp[j] != '.')
				{
					endOfInput = false;
				}
			}
		}
		if (endOfInput)
		{
			break;
		}
		else
		{
			getline(inputStream, temp);
		}
		cout << "Game #" << counterGame << " : ";
		checkBoard(board);
		counterGame += 1;
	}
}

