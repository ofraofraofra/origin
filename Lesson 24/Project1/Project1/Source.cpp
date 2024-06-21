#include <iostream>
#include <vector>
#include <future>
#include <algorithm>

int find_min_index(const std::vector<int>& arr, int start, int end) {
    int min_index = start;
    for (int i = start + 1; i < end; ++i) {
        if (arr[i] < arr[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

void selection_sort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {

        std::promise<int> promise;
        std::future<int> future = promise.get_future();

        std::async(std::launch::async, [&arr, i, n, &promise]() {
            int min_index = find_min_index(arr, i, n);
            promise.set_value(min_index);
            });

        int min_index = future.get();
        std::swap(arr[i], arr[min_index]);
    }
}

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    std::vector<int> arr = { 64, 25, 12, 22, 11 };

    std::cout << "Исходный массив: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    selection_sort(arr);

    std::cout << "Отсортированный массив: ";
    for (int val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
