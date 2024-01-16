#include <iostream>

#define MODE 1

#if defined(MODE)

#if MODE == 0
#error "Необходимо определить MODE"
#endif

#else
#error "Необходимо определить MODE"
#endif

void add(int a, int b) {
    std::cout << "Результат сложения: " << a + b << std::endl;
}

int main() {

    setlocale(LC_ALL, "ru");

    switch (MODE) {
    case 0:
        std::cout << "Работаю в режиме тренировки" << std::endl;
        break;
    case 1:
        std::cout << "Работаю в боевом режиме" << std::endl;
        int num1, num2;
        std::cout << "Введите число 1: ";
        std::cin >> num1;
        std::cout << "Введите число 2: ";
        std::cin >> num2;
        add(num1, num2);
        break;
    default:
        std::cout << "Неизвестный режим. Завершение работы" << std::endl;
    }

}