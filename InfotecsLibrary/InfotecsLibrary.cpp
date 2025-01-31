#include "pch.h"
#include <utility>
#include<string>
#include "InfotecsLibrary.h"

using namespace std;


void FunctionOne(string message)
{
	for (int i = 0; i < message.length(); i++)
	{
		for (int j = 0; j < message.length(0) - 1; j++)
		{
			if (message[j] < message[j + 1])
			{
				char temp = message[j];
				message[j] = message[j + 1];
				message[j + 1] = temp;
			}
		}
	}
	int div = 0;
	for (int i = 0; i < message.length(); i++)
	{
		if ((i + div) % 2 != 0)
		{
			message.erase(i, 1);
			message.insert(i, "KB");
			i += 2;
			div++;
		}
	}
}

int FunctionTwo(string message)
{
	int sum = 0;
	for (int i = 0; i < message.length(); i++)
	{
		if (message[i] == "0" || message[i] == "1" || message[i] == "2" || message[i] == "3" ||
			message[i] == "4" || message[i] == "5" || message[i] == "6" || message[i] == "7" ||
			message[i] == "8" || message[i] == "9")
		{
			string element = message[i];
			sum += stoi(element);
		}
	}
	return sum;
}

bool FunctionThree(int data)
{
	if (((data / 10) > 0) && ((data % 32) == 0))
	{
		return true;
	}
	return false;
}