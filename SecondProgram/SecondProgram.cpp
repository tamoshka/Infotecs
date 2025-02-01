// SecondProgram.cpp: определяет точку входа для приложения.
//

#include "SecondProgram.h"
#define PORT 8080
using namespace std;

int main()
{
    int server_fd, client_fd;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        std::cerr << "Ошибка создания сокета\n";
        return 1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Ошибка привязки\n";
        return 1;
    }

    if (listen(server_fd, 1) < 0) {
        std::cerr << "Ошибка при прослушивании\n";
        return 1;
    }

    std::cout << "Сервер запущен, ожидаю подключения...\n";

    while (true) {
        client_fd = accept(server_fd, (struct sockaddr*)&address, &addrlen);
        if (client_fd < 0) {
            std::cerr << "Ошибка подключения клиента\n";
            continue;
        }

        std::cout << "Клиент подключен\n";

        while (true) {
            int received_number;
            ssize_t bytes = recv(client_fd, &received_number, sizeof(received_number), 0);
            if (bytes <= 0) {
                std::cerr << "Клиент отключился, жду нового...\n";
                close(client_fd);
                break;
            }
            if (FunctionThree(received_number))
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
        }
    }
    close(server_fd);
    return 0;
}
