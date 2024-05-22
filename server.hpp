#include <iostream>
#include <string>
#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;


int server_work(int port, int num_connections){
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Создаем сокет
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        cerr << "socket failed";
        exit(EXIT_FAILURE);
    }

    // Устанавливаем адрес и порт сервера
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    // Bind сокета к адресу и порту
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        cerr << "bind failed";
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
            cerr << "listen failed";
            exit(EXIT_FAILURE);
    }
    vector<int> client_sockets;
    return 0;
} 