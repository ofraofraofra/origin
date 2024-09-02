#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

std::mutex mtx;

void sumVectors(const std::vector<int>& a, const std::vector<int>& b, std::vector<int>& result, int start, int end) {
    for (int i = start; i < end; ++i) {
        result[i] = a[i] + b[i];
    }
}

void benchmark(int numElements, int numThreads) {
    std::vector<int> a(numElements, 1);
    std::vector<int> b(numElements, 2);
    std::vector<int> result(numElements, 0);

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::thread> threads;
    int blockSize = numElements / numThreads;

    for (int i = 0; i < numThreads; ++i) {
        int startIdx = i * blockSize;
        int endIdx = (i == numThreads - 1) ? numElements : startIdx + blockSize;
        threads.emplace_back(sumVectors, std::cref(a), std::cref(b), std::ref(result), startIdx, endIdx);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::lock_guard<std::mutex> lock(mtx);
    std::cout << elapsed.count() << "s      ";
}

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    int numElements[] = { 1000, 10000, 100000, 1000000 };
    int numThreads[] = { 1, 2, 4, 8, 16 };

    std::cout << "Кол-во аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;

    std::cout << "          1000            10000            100000             1000000" << std::endl;

    for (int threads : numThreads) {
        std::cout << threads << " потоков ";

        for (int elements : numElements) {
            benchmark(elements, threads);

        }
        std::cout << std::endl;
    }

    return 0;
}


