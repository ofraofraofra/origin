#pragma once

#include <string>
#include <iostream>
#include "Triangle.h"

class Rec_triangle : public Triangle
{
public:
	Rec_triangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {}

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

