#pragma once

#include <string>
#include <iostream>
#include "Triangle.h"



class Eq_triangle : public Triangle
{
public:

	Eq_triangle(int a) : Triangle(a, a, a, 60, 60, 60) {}

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