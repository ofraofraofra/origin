#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "ru");
    system("chcp 1251");
    
    std::string name;

    std::cout << "������� ���: ";
    std::cin >> name;

    std::cout << "������������, " << name  << "!" << std::endl;

    return 0;
}