#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <mutex>

std::mutex log_mutex;

class Server {
public:
    Server(int port) : port(port) {}

    void start() {
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0) {
            std::cerr << "Не удалось создать сокет.\n";
            return;
        }

        sockaddr_in server_addr{};
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = INADDR_ANY;

        if (bind(server_socket, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            std::cerr << "Не удалось привязать сокет.\n";
            return;
        }

        if (listen(server_socket, 5) < 0) {
            std::cerr << "Ошибка при попытке прослушивания.\n";
            return;
        }

        std::cout << "Сервер слушает на порту " << port << "...\n";

        while (true) {
            sockaddr_in client_addr{};
            socklen_t client_len = sizeof(client_addr);
            int client_socket = accept(server_socket, (sockaddr*)&client_addr, &client_len);
            if (client_socket < 0) {
                std::cerr << "Не удалось принять соединение.\n";
                continue;
            }
            std::thread(&Server::handleClient, this, client_socket).detach();
        }
    }

private:
    int port;

    void handleClient(int client_socket) {
        char buffer[1024];
        int bytes_read = read(client_socket, buffer, sizeof(buffer) - 1);
        if (bytes_read > 0) {
            buffer[bytes_read] = '\0';
            logMessage(buffer);
        }
        close(client_socket);
    }

    void logMessage(const std::string& message) {
        std::lock_guard<std::mutex> lock(log_mutex);
        std::ofstream log_file("log.txt", std::ios::app);
        if (log_file.is_open()) {
            log_file << message << std::endl;
        }
    }
};

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Использование: " << argv[0] << " <порт>\n";
        return 1;
    }

    int port = std::stoi(argv[1]);
    Server server(port);
    server.start();

}
