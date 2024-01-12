#include "Square1.h"


Square::Square(int a) : Rectangle(a, a) {}

	std::string Square::get_name()
	{
		name = "Квадрат";
		return name;
	}

	int Square::get_a() { return a; }
	int Square::get_b() { return b; }
	int Square::get_c() { return c; }
	int Square::get_d() { return d; }
	int Square::get_A() { return A; }
	int Square::get_B() { return B; }
	int Square::get_C() { return C; }
	int Square::get_D() { return D; }

	void Square::print_info()
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

	bool Square::check()
	{
		if (!Rectangle::get_sides_count())
		{
			return false;
		}
		return (this->get_a() == this->get_b() && this->get_b() == this->get_c() && this->get_c() == this->get_d() && this->get_d() == this->get_a()
			&& this->get_A() == 90 && this->get_B() == 90 && this->get_C() == 90 && this->get_D() == 90);
	}

