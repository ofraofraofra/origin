#include "Eq_triangle1.h"

	std::string Eq_triangle::get_name()
	{
		name = "Равносторонний треугольник";
		return name;
	}

	int Eq_triangle::get_a() { return a; }
	int Eq_triangle::get_b() { return a; }
	int Eq_triangle::get_c() { return a; }
	int Eq_triangle::get_A() { return A; }
	int Eq_triangle::get_B() { return A; }
	int Eq_triangle::get_C() { return A; }

	void Eq_triangle::print_info()
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

	bool Eq_triangle::check()
	{
		if (!Triangle::get_sides_count())
		{
			return false;
		}
		return (this->get_a() == this->get_b() && this->get_a() == this->get_c() && this->get_A() == 60 && this->get_B() == 60 && this->get_C() == 60);
	}

