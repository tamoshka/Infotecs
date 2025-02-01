#include "FirstProgram.h"


using namespace std;

bool Checker(string);
void FunctionForFirstThread(string);
void FunctionForSecondThread();
string buffer;
pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex;

int main()
{
	string message;
	while (true)
	{
		cout << "Print the message: ";
		cin >> message;
		pthread_t thread1, thread2;
		pthread_mutex_init(&mutex, NULL);
		pthread_create(&thread2, NULL, FunctionForSecondThread());
		this_thread::sleep_for(chrono::milliseconds(5));
		pthread_create(&thread1, NULL, FunctionForFirstThread(), message);
		pthread_join(thread1, NULL);
		pthread_join(thread2, NULL);
		pthread_mutex_destroy(&mutex);
	}
	return 0;
}

void FunctionForFirstThread(string message)
{
	pthread_mutex_lock(&mutex);
	if (Checker(message))
	{
		FunctionOne(message);
		buffer = message;
	}
	pthread_cond_signal(&condvar);
	pthread_mutex_unlock(&mutex);
}

void FunctionForSecondThread()
{
	pthread_mutex_lock(&mutex);
	pthread_cond_wait(&condvar, &mutex);
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
	pthread_mutex_unlock(&mutex);
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