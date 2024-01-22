#include <iostream>
#include <string>

int function(std::string str, int forbidden_length) {
    if (str.length() != forbidden_length) {
        return str.length();
    }
    else {
        throw std::runtime_error("bad_length");
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    int forbidden_length;
    std::cout << "������� ��������� �����: ";
    std::cin >> forbidden_length;

    std::string userInput;
    while (true) {
        std::cout << "������� �����: ";
        std::cin >> userInput;

        try {
            int length = function(userInput, forbidden_length);
            std::cout << "����� ����� \"" << userInput << "\" ����� " << length << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cout << "�� ����� ����� ��������� �����! �� ��������" << std::endl;
            break;
        }
    }
}