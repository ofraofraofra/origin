#pragma once

#include <string>
#include <iostream>
#include "Triangle.h"

class Rec_triangle : public Triangle
{
public:
	Rec_triangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {
		if (C != 90) throw WrongFigure("Ошибка создания фигуры. Причина: угол С не равен 90");
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

