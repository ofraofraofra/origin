#include <iostream>
#include "Class.h"


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	std::cout << "Вы хотите указать начальное значение счетчика? Введите \"y\", если да или \"n\", если нет : ";
	char answer;
	int count;
	std::cin >> answer;

	if (answer == 'y')
	{
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> count;
		Counter c{ count };
		while (true)
		{
			std::cout << "Введите команду('+', '-', '=' или 'x') : ";
			char answer_sym;
			std::cin >> answer_sym;
			if (answer_sym == '+')
			{
				c.increase();
			}
			else if (answer_sym == '-')
			{
				c.decrease();
			}
			else if (answer_sym == '=')
			{
				int tmp = c.get_count();
				std::cout << tmp << std::endl;
			}
			else {
				break;
			}
		}
	}
	else
	{
		Counter c;
		while (true)
		{
			std::cout << "Введите команду('+', '-', '=' или 'x') : ";
			char answer_sym;
			std::cin >> answer_sym;
			if (answer_sym == '+')
			{
				c.increase();
			}
			else if (answer_sym == '-')
			{
				c.decrease();
			}
			else if (answer_sym == '=')
			{
				int tmp = c.get_count();
				std::cout << tmp << std::endl;
			}
			else {
				break;
			}
		}
	}
	std::cout << "До свидания!";
}
