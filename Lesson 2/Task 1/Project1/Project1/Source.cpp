#include <iostream>
#include <string>

class Calculator
{
private:

	double num1;
	double num2;

public:

	double add()
	{
		return num1 + num2;
	}

	double multiply()
	{
		return num1 * num2;
	}

	double msubtract_1_2()
	{
		return num2 - num1;
	}

	double msubtract_2_1()
	{
		return num1 - num2;
	}

	double divide_1_2()
	{
		return num1 / num2;
	}

	double divide_2_1()
	{
		return num2 / num1;
	}

	bool set_num1(double num1)
	{
		if (num1 != 0)
		{
			this->num1 = num1;
			return true;
		}
		return false;
	}

	bool set_num2(double num2)
	{
		if (num2 != 0)
		{
			this->num2 = num2;
			return true;
		}
		return false;
	}
};
int main(int argc, char** argv)
{
	while (true)
	{
		setlocale(LC_ALL, "ru");
		Calculator c;

		double num1;
		double num2;

		do {
			std::cout << "Введите num1:" << std::endl;
			std::cin >> num1;
			if (!c.set_num1(num1))
			{
				std::cout << "Неверный ввод!" << std::endl;
			}
		} while (!c.set_num1(num1));

		do {
			std::cout << "Введите num2:" << std::endl;
			std::cin >> num2;
			if (!c.set_num2(num2))
			{
				std::cout << "Неверный ввод!" << std::endl;
			}
		} while (!c.set_num2(num2));

		std::cout << "num1 + num2 = " << c.add() << std::endl;

		std::cout << "num1 - num2 = " << c.msubtract_2_1() << std::endl;
		
		std::cout << "num2 - num1 = " << c.msubtract_1_2() << std::endl;

		std::cout << "num1 * num2 = " << c.multiply() << std::endl;
		
		std::cout << "num1 / num2 = " << c.divide_1_2()  << std::endl;
		
		std::cout << "num2 / num1 = " << c.divide_2_1() << std::endl;
		
	}

}