#include <iostream>

#include "Leaver.h"

int main() {
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    Leaver leaver;
    std::string name_l;
    std::cout << "Введите имя: ";
    std::getline(std::cin, name_l);
    std::cout << leaver.leav(name_l) << std::endl;
    return 0;
}