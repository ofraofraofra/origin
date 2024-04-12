#include <iostream>
#include <vector>
#include <algorithm>

void removeDuplicates(std::vector<int>& vec) {

    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

int main() {

    std::vector<int> vec = { 1, 1, 2, 5, 6, 1, 2, 4 };

    std::cout << "[IN]: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    removeDuplicates(vec);

    std::cout << "[OUT]: ";
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
