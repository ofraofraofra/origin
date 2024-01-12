#include <iostream>
#include "math.h"

int main() {

	setlocale(LC_ALL, "ru");

	double num1;
	double num2;
	int operation;
	
	std::cout << "������� ������ �����: ";
	std::cin >> num1;

	std::cout << "������� ������ �����: ";
	std::cin >> num2;

	std::cout << "�������� �������� (1 - ��������, 2 - ���������, 3 - ���������, 4 - �������, 5 - ���������� � �������): ";
	std::cin >> operation;

	switch (operation) {
	case 1:
		std::cout << "��������� ��������: " << sum(num1, num2) << std::endl;
		break;
	case 2:
		std::cout << "��������� ���������: " << diff(num1, num2) << std::endl;
		break;
	case 3:
		std::cout << "��������� ���������: " << multiplication(num1, num2) << std::endl;
		break;
	case 4:
		std::cout << "��������� �������: " << division(num1, num2) << std::endl;
		break;
	case 5:
		std::cout << "��������� ���������� � �������: " << power(num1, num2) << std::endl;
		break;
	default:
		std::cout << "������� ������� ��������." << std::endl;
		break;
	}

	return 0;
}