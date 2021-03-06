// MineSweeper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkCondition(char input)
{
	if (input == '*')
	{
		return true;
	}
	return false;
}

int main()
{
	std::ifstream inputStream;
	inputStream.open("input.txt");
	if (!inputStream.is_open())
	{
		std::cout << "cant open the input.txt file!" << std::endl;
		exit(0);
	}
	while (!inputStream.eof())
	{
		std::string temp;
		std::getline(inputStream, temp);
		std::size_t pos = temp.find(" ");
		int m = std::stoi(temp.substr(0, pos));
		int n = std::stoi(temp.substr(pos));
		
		vector<vector<char>>input;
		for (int i = 0; i < m; i++)
		{
			std::getline(inputStream, temp);
			vector<char> row;
			for (int j = 0; j < n; j++)
			{
				row.push_back(temp[2*j]);
			}
			input.push_back(row);
		}

		vector<vector<char>> output;
		for (int i = 0; i < m; i++)
		{
			vector<char> tmp;
			for (int j = 0; j < n; j++)
			{
				if (checkCondition(input[i][j]))
				{
					tmp.push_back('*');
					continue;
				}
				else
				{
					int counter = 0;
					if (i + 1 < m)
					{
						if (checkCondition(input[i + 1][j])) 
						{
							counter += 1;
						}
						if (j + 1 < n)
						{
							if (checkCondition(input[i + 1][j + 1]))
							{
								counter += 1;
							}
						}
						if (j - 1 >= 0)
						{
							if (checkCondition(input[i + 1][j - 1]))
							{
								counter += 1;
							}
						}
					}
					if (i - 1 >= 0)
					{
						if (checkCondition(input[i - 1][j]))
						{
							counter += 1;
						}
						if (j + 1 < n)
						{
							if (checkCondition(input[i - 1][j + 1]))
							{
								counter += 1;
							}
						}
						if (j - 1 >= 0)
						{
							if (checkCondition(input[i - 1][j - 1]))
							{
								counter += 1;
							}
						}
					}
					if (j + 1 < n)
					{
						if (checkCondition(input[i][j + 1]))
						{
							counter += 1;
						}
					}
					if (j - 1 >= 0)
					{
						if (checkCondition(input[i][j - 1]))
						{
							counter += 1;
						}
					}
					tmp.push_back((int)counter);
				}
			}
			output.push_back(tmp);
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (output[i][j] == '*')
				{
					cout << output[i][j] << " ";
				}
				else
				{
					cout << (int) output[i][j] << " ";
				}
			}
			cout << endl;
		}

		cout << "\n \n \n";
	}
	return 0;
}

