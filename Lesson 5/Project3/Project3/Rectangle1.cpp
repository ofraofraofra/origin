#include "Rectangle1.h"


Rectangle::Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) {}

	std::string Rectangle::get_name()
	{
		name = "Прямоугольник";
		return name;
	}

	int Rectangle::get_a() { return a; }
	int Rectangle::get_b() { return b; }
	int Rectangle::get_c() { return c; }
	int Rectangle::get_d() { return d; }
	int Rectangle::get_A() { return A; }
	int Rectangle::get_B() { return B; }
	int Rectangle::get_C() { return C; }
	int Rectangle::get_D() { return D; }

	void Rectangle::print_info()
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

	bool Rectangle::check()
	{
		if (!Parallelogram::get_sides_count())
		{
			return false;
		}
		return ((this->get_a() == this->get_c()) && (this->get_b() == this->get_d())
			&& this->get_A() == 90 && this->get_B() == 90 && this->get_C() == 90 && this->get_D() == 90);
	}

