// TheTrip.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "fstream"
#include "string"
#include "iostream"
#include "vector"
using namespace std;

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
		int numOfTraveler = std::stoi(temp);
		float totalMoney = 0;
		vector<float> input;
		for (int i = 0; i < numOfTraveler; i++)
		{
			std::getline(inputStream, temp);
			float money = std::stof(temp);
			input.push_back(money);
			totalMoney += money;
		}
		float average = totalMoney / numOfTraveler;
		float output = 0;
		for (int i = 0; i < numOfTraveler; i++)
		{
			if (input[i] > average)
			{
				output += input[i] - average;
			}
		}
		cout << output << "$"<<endl;
	}
}

