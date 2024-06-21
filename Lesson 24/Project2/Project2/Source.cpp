#include <iostream>
#include <vector>
#include <future>
#include <algorithm>
#include <iterator>

template <typename Iterator, typename Function>
void parallel_for_each(Iterator first, Iterator last, Function f) {
    auto length = std::distance(first, last);
    if (length <= 1000) {
        std::for_each(first, last, f);
    }
    else {
        Iterator middle = first;
        std::advance(middle, length / 2);
        auto handle = std::async(std::launch::async, parallel_for_each<Iterator, Function>, first, middle, f);
        parallel_for_each(middle, last, f);
        handle.get();
    }
}

template <typename Container, typename Function>
void parallel_for_each(Container& c, Function f) {
    parallel_for_each(std::begin(c), std::end(c), f);
}

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    std::vector<int> vec(10000, 1);

    parallel_for_each(vec, [](int& n) { n += 1; });

    for (const auto& val : vec) {
        if (val != 2) {
            std::cout << "Не все элементы были обработаны правильно!" << std::endl;
            return 0;
        }
    }

    std::cout << "Все элементы были обработаны правильно!" << std::endl;

    return 0;
}
