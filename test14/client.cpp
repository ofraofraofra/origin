#include <iostream>
#include <cstring>
#include <chrono>
#include <thread>
#include <ctime>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

class Client {
public:
    Client(const std::string& name, const std::string& server_ip, int server_port, int period)
        : name(name), server_ip(server_ip), server_port(server_port), period(period) {}

    void start() {
        while (true) {
            int client_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (client_socket < 0) {
                std::cerr << "Не удалось создать сокет.\n";
                return;
            }

            sockaddr_in server_addr{};
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(server_port);
            inet_pton(AF_INET, server_ip.c_str(), &server_addr.sin_addr);

            if (connect(client_socket, (sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
                std::cerr << "Не удалось подключиться к серверу.\n";
                close(client_socket);
                return;
            }

            std::string message = createTimestamp() + " " + name;
            send(client_socket, message.c_str(), message.size(), 0);

            close(client_socket);
            std::this_thread::sleep_for(std::chrono::seconds(period));
        }
    }

private:
    std::string name;
    std::string server_ip;
    int server_port;
    int period;

    std::string createTimestamp() {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::tm* tm_ptr = std::localtime(&in_time_t);

        char buffer[100];
        std::strftime(buffer, sizeof(buffer), "[%Y-%m-%d %H:%M:%S", tm_ptr);

        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
        sprintf(buffer + strlen(buffer), ".%03ld]", ms.count());

        return std::string(buffer);
    }
};

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Использование: " << argv[0] << " <имя_клиента> <порт_сервера> <период>\n";
        return 1;
    }

    std::string client_name = argv[1];
    int server_port = std::stoi(argv[2]);
    int period = std::stoi(argv[3]);

    Client client(client_name, "127.0.0.1", server_port, period);
    client.start();

}
