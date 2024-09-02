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
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    std::string userInput;
    while (true) {
        std::cout << "Введите слово: ";
        std::cin >> userInput;

        try {
            int length = function(userInput, forbidden_length);
            std::cout << "Длина слова \"" << userInput << "\" равна " << length << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
            break;
        }
    }
}