#include "Is_triangle1.h"


	std::string Is_triangle::get_name()
	{
		name = "Равнобедренный треугольник";
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
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides_count() << std::endl;
		std::cout << "Стороны: a = " << this->get_a() << " b = " << this->get_b() << " c = " << this->get_c() << std::endl;
		std::cout << "Углы: A = " << this->get_A() << " B = " << this->get_B() << " C = " << this->get_C() << std::endl << std::endl;
	}

	bool Is_triangle::check()
	{
		if (!Triangle::get_sides_count())
		{
			return false;
		}
		return ((this->get_a() == this->get_c()) && (this->get_A() == this->get_C()));
	}
