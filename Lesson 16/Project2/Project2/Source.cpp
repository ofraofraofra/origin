#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cout << "[IN]:" << std::endl;
    std::cin >> n;

    std::set<int> uniqueNumbers;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        uniqueNumbers.insert(num);
    }

    std::vector<int> uniqueNumbersVector(uniqueNumbers.begin(), uniqueNumbers.end());

    std::sort(uniqueNumbersVector.rbegin(), uniqueNumbersVector.rend());

    std::cout << "[OUT]:" << std::endl;

    for (int num : uniqueNumbersVector) {
        std::cout << num << std::endl;
    }
}
