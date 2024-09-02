#include "Is_triangle1.h"


	std::string Is_triangle::get_name()
	{
		name = "�������������� �����������";
		return name;
	}

	int Is_triangle::get_a() { return a; }
	int Is_triangle::get_b() { return b; }
	int Is_triangle::get_c() { return a; }
	int Is_triangle::get_A() { return A; }
	int Is_triangle::get_B() { return B; }
	int Is_triangle::get_C() { return A; }

	void Is_triangle::print_info()
	{
		std::cout << this->get_name() << ": " << std::endl;
		if (check())
		{
			std::cout << "����������" << std::endl;
		}
		else {
			std::cout << "������������" << std::endl;
		}
		std::cout << "���������� ������: " << get_sides_count() << std::endl;
		std::cout << "�������: a = " << this->get_a() << " b = " << this->get_b() << " c = " << this->get_c() << std::endl;
		std::cout << "����: A = " << this->get_A() << " B = " << this->get_B() << " C = " << this->get_C() << std::endl << std::endl;
	}

	bool Is_triangle::check()
	{
		if (!Triangle::get_sides_count())
		{
			return false;
		}
		return ((this->get_a() == this->get_c()) && (this->get_A() == this->get_C()));
	}
