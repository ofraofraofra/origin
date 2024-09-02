#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <atomic>
#include <iomanip>

const int numThreads = 5; // количество потоков
const int progressBarLength = 50; // ƒлина прогресс-бара
const int workTime = 5; // ќбщее врем€ работы каждого потока в секундах

std::mutex consoleMutex;

struct ThreadInfo {
    std::thread::id id;
    std::string progress;
    double duration;
    bool finished;
};

std::vector<ThreadInfo> threadInfos(numThreads);

void threadFunction(int threadNum) {
    auto start = std::chrono::high_resolution_clock::now();
    int sleepTime = workTime * 1000 / progressBarLength;

    for (int i = 0; i < progressBarLength; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepTime));
        {
            std::lock_guard<std::mutex> lock(consoleMutex);
            threadInfos[threadNum].progress[i] = '#';
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    {
        std::lock_guard<std::mutex> lock(consoleMutex);
        threadInfos[threadNum].duration = duration.count();
        threadInfos[threadNum].finished = true;
    }
}

void printStatus() {

    std::lock_guard<std::mutex> lock(consoleMutex);
    std::cout << "\033[2J\033[H"; // очистка экрана и перемещени€ курсора в начало

    std::cout << "#   id        Progress Bar                     Time" << std::endl;
    for (int i = 0; i < numThreads; ++i) {
        std::cout << std::setw(2) << i << "  " << std::setw(5) << threadInfos[i].id
            << "  " << threadInfos[i].progress << "  ";
        if (threadInfos[i].finished) {
            std::cout << std::fixed << std::setprecision(2) << threadInfos[i].duration << " секунд.";
        }
        std::cout << std::endl;
    }
}

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        threadInfos[i].progress = std::string(progressBarLength, ' ');
        threadInfos[i].finished = false;
    }

    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back([i]() {
            threadInfos[i].id = std::this_thread::get_id();
            threadFunction(i);
            });
    }

    bool allFinished = false;
    while (!allFinished) {
        allFinished = true;
        printStatus();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        for (int i = 0; i < numThreads; ++i) {
            if (!threadInfos[i].finished) {
                allFinished = false;
            }
        }
    }

    for (auto& thread : threads) {
        thread.join();
    }

    printStatus();

    return 0;
}
