#pragma once

#include <string>
#include <iostream>
#include "Rectangle1.h"

class Square : public Rectangle
{
protected:

public:

	Square(int a);

	std::string get_name();

	int get_a();
	int get_b();
	int get_c();
	int get_d();
	int get_A();
	int get_B();
	int get_C();
	int get_D();

	void print_info() override;

	bool check() override;

};

