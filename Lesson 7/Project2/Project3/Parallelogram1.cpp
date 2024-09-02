#include "Parallelogram1.h"


	Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {
		if (a != c || b != d) throw WrongFigure("������ �������� ������. �������: ������� a,c � b,d ������� �� �����");
		if (A != C || B != D) throw WrongFigure("������ �������� ������. �������: ���� A,C � B,D ������� �� �����");
	}
	
	std::string Parallelogram::get_name()
	{
		name = "��������������";
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
			std::cout << "����������" << std::endl;
		}
		else {
			std::cout << "������������" << std::endl;
		}
		std::cout << "���������� ������: " << get_sides_count() << std::endl;
		std::cout << "�������: a = " << this->get_a() << " b = " << this->get_b() << " c = " << this->get_c() << " d = " << this->get_d() << std::endl;
		std::cout << "����: A = " << this->get_A() << " B = " << this->get_B() << " C = " << this->get_C() << " D = " << this->get_D() << std::endl << std::endl;
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



