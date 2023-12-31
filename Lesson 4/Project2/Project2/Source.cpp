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

};


class Triangle : public Figure
{
protected:

	int a, b, c, A, B, C;

public:
	
	Triangle(int a, int b, int c, int A, int B, int C ) : Figure(3)
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

};

void print_info(Triangle* ptr_t)
{
	std::cout << ptr_t->get_name() << ": " << std::endl;
	std::cout << "Стороны: a = " << ptr_t->get_a() << " b = " << ptr_t->get_b() << " c = " << ptr_t->get_c() << std::endl;
	std::cout << "Углы: A = " << ptr_t->get_A() << " B = " << ptr_t->get_B() << " C = " << ptr_t->get_C() << std::endl << std::endl;
}
void print_info(Rec_triangle* ptr_rec)
{
	std::cout << ptr_rec->get_name() << ": " << std::endl;
	std::cout << "Стороны: a = " << ptr_rec->get_a() << " b = " << ptr_rec->get_b() << " c = " << ptr_rec->get_c() << std::endl;
	std::cout << "Углы: A = " << ptr_rec->get_A() << " B = " << ptr_rec->get_B() << " C = " << ptr_rec->get_C() << std::endl << std::endl;
}
void print_info(Is_triangle* ptr_is)
{
	std::cout << ptr_is->get_name() << ": " << std::endl;
	std::cout << "Стороны: a = " << ptr_is->get_a() << " b = " << ptr_is->get_b() << " c = " << ptr_is->get_c() << std::endl;
	std::cout << "Углы: A = " << ptr_is->get_A() << " B = " << ptr_is->get_B() << " C = " << ptr_is->get_C() << std::endl << std::endl;
}
void print_info(Eq_triangle* ptr_eq)
{
	std::cout << ptr_eq->get_name() << ": " << std::endl;
	std::cout << "Стороны: a = " << ptr_eq->get_a() << " b = " << ptr_eq->get_b() << " c = " << ptr_eq->get_c() << std::endl;
	std::cout << "Углы: A = " << ptr_eq->get_A() << " B = " << ptr_eq->get_B() << " C = " << ptr_eq->get_C() << std::endl << std::endl;
}
void print_info(Quadrangle* ptr_q)
{
	std::cout << ptr_q->get_name() << ": " << std::endl;
	std::cout << "Стороны: a = " << ptr_q->get_a() << " b = " << ptr_q->get_b() << " c = " << ptr_q->get_c() << " d = " << ptr_q->get_d() << std::endl;
	std::cout << "Углы: A = " << ptr_q->get_A() << " B = " << ptr_q->get_B() << " C = " << ptr_q->get_C() << " D = " << ptr_q->get_D() << std::endl << std::endl;
}
void print_info(Rectangle* ptr_rec)
{
	std::cout << ptr_rec->get_name() << ": " << std::endl;
	std::cout << "Стороны: a = " << ptr_rec->get_a() << " b = " << ptr_rec->get_b() << " c = " << ptr_rec->get_c() << " d = " << ptr_rec->get_d() << std::endl;
	std::cout << "Углы: A = " << ptr_rec->get_A() << " B = " << ptr_rec->get_B() << " C = " << ptr_rec->get_C() << " D = " << ptr_rec->get_D() << std::endl << std::endl;
}
void print_info(Square* ptr_sq)
{
	std::cout << ptr_sq->get_name() << ": " << std::endl;
	std::cout << "Стороны: a = " << ptr_sq->get_a() << " b = " << ptr_sq->get_b() << " c = " << ptr_sq->get_c() << " d = " << ptr_sq->get_d() << std::endl;
	std::cout << "Углы: A = " << ptr_sq->get_A() << " B = " << ptr_sq->get_B() << " C = " << ptr_sq->get_C() << " D = " << ptr_sq->get_D() << std::endl << std::endl;
}
void print_info(Parallelogram* ptr_p)
{
	std::cout << ptr_p->get_name() << ": " << std::endl;
	std::cout << "Стороны: a = " << ptr_p->get_a() << " b = " << ptr_p->get_b() << " c = " << ptr_p->get_c() << " d = " << ptr_p->get_d() << std::endl;
	std::cout << "Углы: A = " << ptr_p->get_A() << " B = " << ptr_p->get_B() << " C = " << ptr_p->get_C() << " D = " << ptr_p->get_D() << std::endl << std::endl;
}
void print_info(Rhombus* ptr_r)
{
	std::cout << ptr_r->get_name() << ": " << std::endl;
	std::cout << "Стороны: a = " << ptr_r->get_a() << " b = " << ptr_r->get_b() << " c = " << ptr_r->get_c() << " d = " << ptr_r->get_d() << std::endl;
	std::cout << "Углы: A = " << ptr_r->get_A() << " B = " << ptr_r->get_B() << " C = " << ptr_r->get_C() << " D = " << ptr_r->get_D() << std::endl << std::endl;
}


int main()
{
	setlocale(LC_ALL, "ru");

	Triangle t (10, 20, 30, 50, 60, 70);
	print_info(&t);
	Rec_triangle r(10, 20, 30, 50, 60);
	print_info(&r);
	Is_triangle i(10, 20, 50, 60);
	print_info(&i);
	Eq_triangle eq(30);
	print_info(&eq);
	Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
	print_info(&q);
	Rectangle rec(10,20);
	print_info(&rec);
	Square sq(20);
	print_info(&sq);
	Parallelogram par(20, 30, 30, 40);
	print_info(&par);
	Rhombus rom(30, 30, 40);
	print_info(&rom);


}