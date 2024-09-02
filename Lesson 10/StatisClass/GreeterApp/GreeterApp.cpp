#include <iostream>
#include "Greeter.h"
#include "Leaver.h"

int main() {
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    Greeter greeter;
    std::string name;
    std::cout << "Введите имя: ";
    std::getline(std::cin, name);
    std::cout << greeter.greet(name) << std::endl;
    Leaver leaver;
    std::string name_l;
    std::cout << "Введите имя: ";
    std::getline(std::cin, name_l);
    std::cout << leaver.leav(name_l) << std::endl;
    return 0;
}