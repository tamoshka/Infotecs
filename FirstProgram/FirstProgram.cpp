#include "FirstProgram.h"

using namespace std;

bool Checker(string);
void FunctionForFirstThread(string);
void FunctionForSecondThread();
string buffer;
mutex mtx;

int main()
{
	string message;
	while (true)
	{
		cout << "Print the message: ";
		cin >> message;
		thread th1(FunctionForFirstThread, message);
		this_thread::sleep_for(chrono::milliseconds(5));
		thread th2(FunctionForSecondThread);
		th1.join();
		th2.join();
	}
}

void FunctionForFirstThread(string message)
{
	mtx.lock();
	if (Checker(message))
	{
		FunctionOne(message);
		buffer = message;
	}
	mtx.unlock();
}

void FunctionForSecondThread()
{
	mtx.lock();
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
		cout << '\n';
	}
	else
	{
		cout << '\n';
		cout << "Exception";
		cout << '\n';
	}
	mtx.unlock();
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