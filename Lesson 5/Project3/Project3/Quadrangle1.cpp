#include "Quadrangle1.h"


Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}


	std::string Quadrangle::get_name()
	{
		name = "Четырехугольник";
		return name;
	}

	int Quadrangle::get_a() { return a; }
	int Quadrangle::get_b() { return b; }
	int Quadrangle::get_c() { return c; }
	int Quadrangle::get_d() { return d; }
	int Quadrangle::get_A() { return A; }
	int Quadrangle::get_B() { return B; }
	int Quadrangle::get_C() { return C; }
	int Quadrangle::get_D() { return D; }


	void Quadrangle::print_info()
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

	bool Quadrangle::check()
	{
		return this->get_sides_count() == 4 && (this->get_A() + this->get_B() + this->get_C() + this->get_D()) == 360;
	}

