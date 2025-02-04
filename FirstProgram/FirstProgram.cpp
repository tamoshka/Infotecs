#include "FirstProgram.h"


using namespace std;

bool Checker(string);
void* FunctionForFirstThread(void*);
int atoi(const char* nptr);
void* FunctionForSecondThread(void*);
string buffer;
int signal_sent = 0;
pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex;

#define PORT 8080
#define SERVER_IP "127.0.0.1"

int main()
{
	int sock;
	struct sockaddr_in serv_addr;
	string message;
	while (true)
	{
		sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock == -1) {
			std::cerr << "Ошибка создания сокета\n";
			return 1;
		}

		serv_addr.sin_family = AF_INET;
		serv_addr.sin_port = htons(PORT);
		if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
			std::cerr << "Неверный адрес сервера\n";
			return 1;
		}

		while (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
			std::cerr << "Не удалось подключиться, повтор через 3 сек...\n";
			std::this_thread::sleep_for(std::chrono::seconds(3));
		}

		std::cout << "Подключение установлено\n";
		int number = 0;
		while (true)
		{
			cout << "Print the message: ";
			cin >> message;
			pthread_t thread1, thread2;
			pthread_mutex_init(&mutex, NULL);
			int sum;
			pthread_create(&thread2, NULL, FunctionForSecondThread, sum);
			this_thread::sleep_for(chrono::milliseconds(5));
			pthread_create(&thread1, NULL, FunctionForFirstThread, message);
			ssize_t bytes = send(sock, &sum, sizeof(sum), 0);
			if (bytes <= 0) {
				std::cerr << "Соединение потеряно, переподключение...\n";
				close(sock);
				break;
			}
			std::cout << "Отправлено число: " << sum << std::endl;
			pthread_join(thread1, NULL);
			pthread_join(thread2, NULL);
			pthread_mutex_destroy(&mutex);
		}
	}
	return 0;
}

void* FunctionForFirstThread(void* param)
{
	string message = &param;
	pthread_mutex_lock(&mutex);
	if (Checker(message))
	{
		FunctionOne(message);
		buffer = message;
	}
	pthread_cond_signal(&condvar);
	pthread_mutex_unlock(&mutex);
}

void* FunctionForSecondThread(void* param2)
{
	int sum = &param2;
	pthread_mutex_lock(&mutex);
	while (!signal_sent)
	{
		pthread_cond_wait(&condvar, &mutex);
	}
	string message = buffer;
	buffer.erase(0, buffer.size());
	cout << message;
	pthread_mutex_unlock(&mutex);
	sum = FunctionTwo(message);
}

bool Checker(string message)
{
	if (message.size() > 64)
	{
		return false;
	}
	for (long unsigned int i = 0; i < message.size(); i++)
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