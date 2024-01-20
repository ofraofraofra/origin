#pragma once

#include <string>
#include <iostream>
#include "Triangle.h"



class Eq_triangle : public Triangle
{
public:

	Eq_triangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
		if (a != b || b != c || c!= a) throw WrongFigure("Ошибка создания фигуры. Причина: есть неравные стороны");
		if (A != B || B != C || C != A) throw WrongFigure("Ошибка создания фигуры. Причина: есть неравные углы");
	}

	std::string get_name();

	int get_a();
	int get_b();
	int get_c();
	int get_A();
	int get_B();
	int get_C();

	void print_info() override;

	bool check() override;

};