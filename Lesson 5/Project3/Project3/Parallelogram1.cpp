#include "Parallelogram1.h"


Parallelogram::Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {}

	std::string Parallelogram::get_name()
	{
		name = "Параллелограмм";
		return name;
	}

	int Parallelogram::get_a() { return a; }
	int Parallelogram::get_b() { return b; }
	int Parallelogram::get_c() { return c; }
	int Parallelogram::get_d() { return d; }
	int Parallelogram::get_A() { return A; }
	int Parallelogram::get_B() { return B; }
	int Parallelogram::get_C() { return C; }
	int Parallelogram::get_D() { return D; }

	void Parallelogram::print_info()
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

	bool Parallelogram::check()
	{
		if (!Quadrangle::get_sides_count())
		{
			return false;
		}
		return (this->get_a() == this->get_c() && this->get_b() == this->get_d()
			&& this->get_A() == this->get_C() && this->get_B() == this->get_D());

	}



