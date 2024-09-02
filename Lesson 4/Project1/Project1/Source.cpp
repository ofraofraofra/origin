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
	Figure (int a)
	{
		sides_count = a ;
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
public:
	
	Triangle () : Figure (3)
	{

	}

	std::string get_name()
	{
		name = "Треугольник";
		return name;
	}
};

class Quadrangle : public Figure
{
public:
	Quadrangle() : Figure (4)
	{

	}

	std::string get_name()
	{
		name = "Четырехугольник";
		return name;
	}
};


int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Количество сторон: " << std::endl;
	Figure f;
	std::cout << f.get_name() << ": " << f.get_sides_count() << std::endl;
	Triangle t;
	std::cout << t.get_name() << ": " << t.get_sides_count() << std::endl;
	Quadrangle q;
	std::cout << q.get_name() << ": " << q.get_sides_count() << std::endl;
}