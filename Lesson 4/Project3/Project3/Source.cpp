#include <iostream>
#include <string>

class Figure
{
private:
protected:

	int sides_count;
	std::string name;

public:
	Figure() : Figure(0) {}

	Figure(int a)
	{
		sides_count = a;
	}
	int get_sides_count()
	{
		return sides_count;
	}

	std::string get_name()
	{
		name = "Фигура";
		return name;
	}

	virtual void print_info()
	{
		std::cout << this->get_name() << ": " << std::endl;
		if (check())
		{ 
			std::cout << "Правильная" << std::endl;
		}
		else {
			std::cout << "Неправильная" << std::endl;
		}
		std::cout << "Количество сторон: " << get_sides_count() << std::endl << std::endl;

	}

	virtual bool check()
		{
			return get_sides_count() == 0;
		}

};


class Triangle : public Figure
{
protected:

	int a, b, c, A, B, C;

public:

	Triangle(int a, int b, int c, int A, int B, int C) : Figure(3)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;

	}

	std::string get_name()
	{
		name = "Треугольник";
		return name;
	}

	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }

	void print_info() override
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

	bool check() override
	{
		return this->get_sides_count() == 3 && (this->get_A() + this->get_B() + this->get_C()) == 180;
	}

};


class Rec_triangle : public Triangle
{
public:
	Rec_triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
	{
	}

	std::string get_name()
	{
		name = "Прямоугольный треугольник";
		return name;
	}

	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }

	void print_info() override
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

	bool check() override
	{
		if (!Triangle::get_sides_count())
		{
			return false;
		}
		return this->get_C() == 90;
	}
};

class Is_triangle : public Triangle
{
public:

	Is_triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {}

	std::string get_name()
	{
		name = "Равнобедренный треугольник";
		return name;
	}

	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return a; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return A; }

	void print_info() override
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

	bool check() override
	{
		if (!Triangle::get_sides_count())
		{
			return false;
		}
		return ((this->get_a() == this->get_c()) && (this->get_A() == this->get_C()));
	}

};

class Eq_triangle : public Triangle
{
public:

	Eq_triangle(int a) : Triangle(a, a, a, 60, 60, 60) {}

	std::string get_name()
	{
		name = "Равносторонний треугольник";
		return name;
	}

	int get_a() { return a; }
	int get_b() { return a; }
	int get_c() { return a; }
	int get_A() { return A; }
	int get_B() { return A; }
	int get_C() { return A; }

	void print_info() override
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

	bool check() override
	{
		if (!Triangle::get_sides_count())
		{
			return false;
		}
		return (this->get_a() == this->get_b() && this->get_a() == this->get_c() && this->get_A() == 60 && this->get_B() == 60 && this->get_C() == 60 );
	}

};

class Quadrangle : public Figure
{
protected:

	int a, b, c, d, A, B, C, D;

public:

	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Figure(4)
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


	std::string get_name()
	{
		name = "Четырехугольник";
		return name;
	}

	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_d() { return d; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	int get_D() { return D; }


	void print_info() override
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

	bool check() override
	{
		return this->get_sides_count() == 4 && (this->get_A() + this->get_B() + this->get_C() + this->get_D()) == 360;
	}
};


class Parallelogram : public Quadrangle
{
protected:

public:

	Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {}

	std::string get_name()
	{
		name = "Параллелограмм";
		return name;
	}

	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_d() { return d; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	int get_D() { return D; }

	void print_info() override
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

	bool check() override
	{
		if (!Quadrangle::get_sides_count())
		{
			return false;
		}
		return (this->get_a() == this->get_c() && this->get_b() == this->get_d()
			&& this->get_A() == this->get_C() && this->get_B() == this->get_D());
		
	}
	

};


class Rhombus : public Parallelogram
{
protected:

public:

	Rhombus(int a, int A, int B) : Parallelogram(a, a, A, B) {}

	std::string get_name()
	{
		name = "Ромб";
		return name;
	}

	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_d() { return d; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	int get_D() { return D; }

	void print_info() override
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

	bool check() override
	{
		if (!Parallelogram::get_sides_count())
		{
			return false;
		}
		return (this->get_a() == this->get_b() && this->get_b() == this->get_c() && this->get_c() == this->get_d() && this->get_d() == this->get_a()
			&& this->get_A() == this->get_C() && this->get_B() == this->get_D() );
	}

};

class Rectangle : public Parallelogram
{
protected:

public:

	Rectangle(int a, int b) : Parallelogram(a, b, 90, 90) {}

	std::string get_name()
	{
		name = "Прямоугольник";
		return name;
	}

	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_d() { return d; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	int get_D() { return D; }

		void print_info() override
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

	bool check() override
	{
		if (!Parallelogram::get_sides_count())
		{
			return false;
		}
		return ( (this->get_a() == this->get_c()) && (this->get_b() == this->get_d()) 
			&& this->get_A() == 90 && this->get_B() == 90 && this->get_C() == 90 && this->get_D() == 90);
	}

};

class Square : public Rectangle
{
protected:

public:

	Square(int a) : Rectangle(a, a) {}

	std::string get_name()
	{
		name = "Квадрат";
		return name;
	}

	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_d() { return d; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	int get_D() { return D; }

	void print_info() override
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

	bool check() override
	{
		if (!Rectangle::get_sides_count())
		{
			return false;
		}
		return (this->get_a() == this->get_b() && this->get_b() == this->get_c() && this->get_c() == this->get_d() && this->get_d() == this->get_a()
			&& this->get_A() == 90 && this->get_B() == 90 && this->get_C() == 90 && this->get_D() == 90);
	}

};


int main()
{
	setlocale(LC_ALL, "ru");

	Figure f;
	f.print_info();

	Triangle t(10, 20, 30, 50, 60, 70);
	Figure* par_tri = &t;
	par_tri->print_info();

	Rec_triangle r(10, 20, 30, 50, 60);
	Figure* par_r = &r;
	par_r->print_info();

	Is_triangle i(10, 20, 50, 60);
	Figure* par_is = &i;
	par_is->print_info();

	Eq_triangle eq(30);
	Figure* par_eq = &eq;
	par_eq->print_info();

	Quadrangle q(10, 20, 30, 40, 90, 70, 120, 80);
	Figure* par_q = &q;
	par_q->print_info();

	Rectangle rec(10, 20);
	Figure* par_rec = &rec;
	par_rec->print_info();

	Rhombus rom(30, 30, 40);
	Figure* par_rom = &rom;
	par_rom->print_info();

	Square sq(20);
	Figure* par_sq = &sq;
	par_sq->print_info();
	
	Parallelogram par(20, 30, 30, 40);
	Figure* par_par = &par;
	par_par->print_info();


}