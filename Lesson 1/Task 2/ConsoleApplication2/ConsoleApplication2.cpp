#include <iostream>
#include <string>

struct person
{
	int number_count;
	std::string first_name;
	double balance;
};
void change_balance(person& p, double balance) // ссылка
{
	p.balance = balance;
}
int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	system("chcp 1251");

	person pers;

	std::cout << "Введите номер счета: " << std::endl;
	int number_count;
	std::cin >> number_count;
	pers.number_count = number_count;

	std::cout << "Введите имя владельца: " << std::endl;
	std::string first_name;
	std::cin >> first_name;
	pers.first_name = first_name;

	std::cout << "Введите баланс: " << std::endl;
	double balance;
	std::cin >> balance;
	pers.balance = balance;

	std::cout << "Введите новый баланс: " << std::endl;
	std::cin >> balance;
	change_balance(pers, balance);

	std::cout << "Ваш счет: " << pers.first_name << ", "<< pers.number_count << ", " << pers.balance << std::endl;
}
