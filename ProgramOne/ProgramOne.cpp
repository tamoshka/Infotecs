#include <iostream>
#include "LibraryInfotecs.h"

using namespace std;

bool Checker(string);

int main()
{
	string buffer;
	string message;
	cout << "Введите строку: ";
	cin >> message;
	if (Checker(message))
	{
		buffer = message;
		FunctionOne(buffer);
		cout << buffer;
	}
}

bool Checker(string message)
{
	if (message.size() > 64)
	{
		return false;
	}
	for (int i = 0; i < message.size(); i++)
	{
		if (message[i] != '0' && message[i] != '1' && message[i] != '2' && message[i] != '3' &&
			message[i] != '4' && message[i] != '5' && message[i] != '6' && message[i] != '7' &&
			message[i] != '8' && message[i] != '9')
		{
			return false;
		}
	}
	return true;
}
