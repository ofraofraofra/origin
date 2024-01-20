#include "Rec_triangle1.h"


	std::string Rec_triangle::get_name()
	{
		name = "������������� �����������";
		return name;
	}

	int Rec_triangle::get_a() { return a; }
	int Rec_triangle::get_b() { return b; }
	int Rec_triangle::get_c() { return c; }
	int Rec_triangle::get_A() { return A; }
	int Rec_triangle::get_B() { return B; }
	int Rec_triangle::get_C() { return C; }

	void Rec_triangle::print_info()
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

	bool Rec_triangle::check()
	{
		if (!Triangle::get_sides_count())
		{
			return false;
		}
		return this->get_C() == 90;
	}
