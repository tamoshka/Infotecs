#include <iostream>
#include "LibraryInfotecs.h"

using namespace std;

bool Checker(string);

int main()
{
	string buffer;
	string message;
	cout << "Print the message: ";
	cin >> message;
	if (Checker(message))
	{
		buffer = message;
		FunctionOne(buffer);
	}
	cout << buffer;
	int sum = FunctionTwo(buffer);
	if (FunctionThree(sum))
	{
		cout << '\n';
		cout << buffer;
		cout << '\n';
		cout << sum;
	}
	else
	{
		cout << '\n';
		cout << "Exception";
	}
	buffer.erase(0, buffer.size());
	cout << buffer;
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