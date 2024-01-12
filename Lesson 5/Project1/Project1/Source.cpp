#include <iostream>
#include "math.h"

int main() {

	setlocale(LC_ALL, "ru");

	double num1;
	double num2;
	int operation;
	
	std::cout << "Введите первое число: ";
	std::cin >> num1;

	std::cout << "Введите второе число: ";
	std::cin >> num2;

	std::cout << "Выберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> operation;

	switch (operation) {
	case 1:
		std::cout << "Результат сложения: " << sum(num1, num2) << std::endl;
		break;
	case 2:
		std::cout << "Результат вычитания: " << diff(num1, num2) << std::endl;
		break;
	case 3:
		std::cout << "Результат умножения: " << multiplication(num1, num2) << std::endl;
		break;
	case 4:
		std::cout << "Результат деления: " << division(num1, num2) << std::endl;
		break;
	case 5:
		std::cout << "Результат возведения в степень: " << power(num1, num2) << std::endl;
		break;
	default:
		std::cout << "Неверно выбрана операция." << std::endl;
		break;
	}

	return 0;
}