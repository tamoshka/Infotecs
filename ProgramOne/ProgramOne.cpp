#include <iostream>
#include <thread>
#include <mutex>
#include "LibraryInfotecs.h"

using namespace std;

bool Checker(string);
void FunctionForFirstThread(string);
void FunctionForSecondThread();
string buffer;

int main()
{
	thread threadOne, threadTwo;
	mutex mutex;
	string message;
	while (true)
	{
		cout << "Print the message: ";
		cin >> message;
		FunctionForFirstThread(message);
		FunctionForSecondThread();
	}
}

void FunctionForFirstThread(string message)
{
	if (Checker(message))
	{
		FunctionOne(message);
		buffer = message;
	}
}

void FunctionForSecondThread()
{
	string message = buffer;
	buffer.erase(0, buffer.size());
	cout << message;
	int sum = FunctionTwo(message);
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