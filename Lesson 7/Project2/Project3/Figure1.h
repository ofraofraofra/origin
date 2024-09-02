#pragma once

#include <string>
#include <iostream>

class Figure
{
private:
protected:

	int sides_count;
	std::string name;

public:
	Figure() : Figure(0) {};

	Figure(int a);

	int get_sides_count();

	std::string get_name();

	virtual void print_info();

	virtual bool check();

};

