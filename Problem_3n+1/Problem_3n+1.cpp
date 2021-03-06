// Problem_3n+1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int MaxSycle(int number, int sycle)
{
	sycle += 1;
	if (number == 1)
	{
		return sycle;
	}
	else if (number % 2 == 0)
	{
		return MaxSycle(number / 2, sycle);
	}
	else
	{
		return MaxSycle((number * 3) + 1, sycle);
	}
}

int main()
{
	ifstream inputStream;
	inputStream.open("input.txt");
	if (!inputStream.is_open())
	{
		cout << "can not open the input.txt file!" << endl << "please insert any keyt!!!";
		cin.get();
		exit(0);
	}
	while (!inputStream.eof())
	{
		std::string temp;
		std::getline(inputStream, temp);
		std::size_t pos = temp.find(" ");
		int firstNumber = std::stoi(temp.substr(0, pos));
		int secondNumber = std::stoi(temp.substr(pos));
		int maxSycle = 0;
		for (int i = firstNumber; i <= secondNumber; i++)
		{
			int temp = MaxSycle(i, 0);
			if (temp> maxSycle)
			{
				maxSycle = temp;
			}
		}

		cout << firstNumber << " " << secondNumber << " "<< maxSycle << endl;
	}
	
	cin.get();
    return 0;
}

