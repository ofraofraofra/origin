#include <iostream>
#include <string>
#include <thread>
#include "thread_pool.h"

void print_message(const std::string& message) {
    std::cout << message << std::endl;
}

int main() {
    size_t num_threads = std::thread::hardware_concurrency();
    thread_pool pool(num_threads);

    for (int i = 0; i < 10; ++i) {
        pool.submit(print_message, "Task " + std::to_string(i * 2 + 1));
        pool.submit(print_message, "Task " + std::to_string(i * 2 + 2));
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
