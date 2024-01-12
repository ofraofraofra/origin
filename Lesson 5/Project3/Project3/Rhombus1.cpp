#include "Rhombus1.h"


Rhombus::Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B) {}

	std::string Rhombus::get_name()
	{
		name = "Ромб";
		return name;
	}

	int Rhombus::get_a() { return a; }
	int Rhombus::get_b() { return b; }
	int Rhombus::get_c() { return c; }
	int Rhombus::get_d() { return d; }
	int Rhombus::get_A() { return A; }
	int Rhombus::get_B() { return B; }
	int Rhombus::get_C() { return C; }
	int Rhombus::get_D() { return D; }

	void Rhombus::print_info()
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
		std::cout << "Стороны: a = " << this->get_a() << " b = " << this->get_b() << " c = " << this->get_c() << " d = " << this->get_d() << std::endl;
		std::cout << "Углы: A = " << this->get_A() << " B = " << this->get_B() << " C = " << this->get_C() << " D = " << this->get_D() << std::endl << std::endl;
	}

	bool Rhombus::check()
	{
		if (!Parallelogram::get_sides_count())
		{
			return false;
		}
		return (this->get_a() == this->get_b() && this->get_b() == this->get_c() && this->get_c() == this->get_d() && this->get_d() == this->get_a()
			&& this->get_A() == this->get_C() && this->get_B() == this->get_D());
	}

