#pragma once

#include <string>
#include <iostream>
#include "Triangle.h"

class Is_triangle : public Triangle
{
public:

	Is_triangle(int a, int b, int ñ, int A, int B, int Ñ);

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

