#pragma once

#include <string>
#include <iostream>
#include "Figure1.h"

class Triangle : public Figure
{
protected:

	int a, b, c, A, B, C;

public:

	Triangle(int a, int b, int c, int A, int B, int C);

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
