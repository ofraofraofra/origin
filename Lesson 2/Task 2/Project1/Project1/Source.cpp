#include <iostream>

class Counter
{
private:

	 int count;

public:

	Counter(int count ) { 
		this->count = count;
	}
	Counter() {
		this->count = 1;
	}
	void increase()
	{
		++count;
	}
	void decrease()
	{
		--count;
	}
	int get_count()
	{
		return count;
	}
	int set_count( int count)
	{
		return this->count = count;
	}
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru");
	std::cout << "�� ������ ������� ��������� �������� ��������? ������� \"y\", ���� �� ��� \"n\", ���� ��� : ";
	char answer;
	int count;
	std::cin >> answer;

	if (answer == 'y')
	{
		std::cout << "������� ��������� �������� ��������: ";
		std::cin >> count;
		Counter c { count };
		while (true)
		{
			std::cout << "������� �������('+', '-', '=' ��� 'x') : ";
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
			std::cout << "������� �������('+', '-', '=' ��� 'x') : ";
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
	std::cout << "�� ��������!";
}
