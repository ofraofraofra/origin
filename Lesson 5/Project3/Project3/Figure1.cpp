#include "Figure1.h"


Figure::Figure(int a)
	{
		sides_count = a;
	}
	int Figure::get_sides_count()
	{
		return sides_count;
	}

	std::string Figure::get_name()
	{
		name = "������";
		return name;
	}

	void Figure::print_info()
	{
		std::cout << this->get_name() << ": " << std::endl;
		if (check())
		{
			std::cout << "����������" << std::endl;
		}
		else {
			std::cout << "������������" << std::endl;
		}
		std::cout << "���������� ������: " << get_sides_count() << std::endl << std::endl;

	}

	bool Figure::check()
	{
		return get_sides_count() == 0;
	}
