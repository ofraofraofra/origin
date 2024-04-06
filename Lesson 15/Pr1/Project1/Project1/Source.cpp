#include <iostream>
#include <vector>

template<class T>
T square(T x) {
    return x * x;
}

template<class T>
std::vector<T> square(const std::vector<T>& vec) {
    std::vector<T> result;
    for (const auto& elem : vec) {
        result.push_back(elem * elem);
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    int num = 4;
    std::cout << "[IN]: " << num << std::endl;    
    std::cout << "[OUT]: " << square(num) << std::endl;

    std::vector<int> vec{ 1, 10,7,-9,4 };
    std::cout << "[IN]: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    };
    std::cout << std::endl;


    std::vector<int> squared_vec = square(vec);
    std::cout << "[OUT]: ";
    for (const auto& elem : squared_vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
