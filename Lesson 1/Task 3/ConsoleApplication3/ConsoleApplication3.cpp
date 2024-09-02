#include <iostream>
#include <string>

struct address
{
	std::string city;
	std::string street;
	int number_home;
	int number_apartment;
	int index;
};

void write_address(address& a)
{
	std::cout << std::endl;
	std::cout << "Город: " << a.city << std::endl;
	std::cout << "Улица: " << a.street << std::endl;
	std::cout << "Номер дома: " << a.number_home << std::endl;
	std::cout << "Номер квартиры: " << a.number_apartment << std::endl;
	std::cout << "Индекс: " << a.index << std::endl;
}


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	system("chcp 1251");

	while (true)
	{
		address a;
		std::cout << "Введите город: " << std::endl;
		std::string city;
		std::cin >> city;
		a.city = city;

		std::cout << "Введите улицу: " << std::endl;
		std::string street;
		std::cin >> street;
		a.street = street;

		std::cout << "Введите номер дома: " << std::endl;
		int number_home;
		std::cin >> number_home;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Попробуйте снова: " << std::endl;
			continue;
		}
		a.number_home = number_home;

		std::cout << "Введите номер квартиры: " << std::endl;
		int number_apartment;
		std::cin >> number_apartment;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Попробуйте снова: " << std::endl;
			continue;
		}
		a.number_apartment = number_apartment;

		std::cout << "Введите индекс: " << std::endl;
		int index;
		std::cin >> index;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Попробуйте снова: " << std::endl;
			continue;
		}
		a.index = index;

		write_address(a);

		std::cout << std::endl;
	}

}