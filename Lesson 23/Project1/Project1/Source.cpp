#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>
#include <condition_variable>

std::atomic<int> clientCount(0);  // Счётчик клиентов
std::mutex mtx;
std::condition_variable cv;
int maxClients;
bool queueFullNotified = false; // Уведомление о заполнении очереди

void client() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lock(mtx);
        if (clientCount >= maxClients) {
            if (!queueFullNotified) {
                std::cout << "Очередь заполнена. Нельзя добавить больше клиентов." << std::endl;
                queueFullNotified = true;
            }
            cv.wait(lock, [] { return clientCount == 0; });
            std::cout << "Возобновляется приём клиентов." << std::endl;
        }
        ++clientCount;
        std::cout << "Прибыл клиент. Текущее количество клиентов: " << clientCount << std::endl;
        queueFullNotified = false;
        cv.notify_all();
    }
}

void operator_() {
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::unique_lock<std::mutex> lock(mtx);
        if (clientCount > 0) {
            --clientCount;
            std::cout << "Операционист обслужил клиента. Текущее количество клиентов: " << clientCount << std::endl;
            if (clientCount == 0) {
                cv.notify_all();
            }
        }
    }
}

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    std::cout << "Введите максимальное количество клиентов в очереди: ";
    std::cin >> maxClients;

    std::thread clientThread(client);
    std::thread operatorThread(operator_);

    clientThread.join();
    operatorThread.join();

    return 0;
}
