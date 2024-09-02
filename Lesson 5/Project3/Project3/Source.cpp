#include <iostream>
#include <string>

#include "Figure1.h"
#include "Triangle.h"
#include "Rec_triangle1.h"
#include "Is_triangle1.h"
#include "Eq_triangle1.h"
#include "Quadrangle1.h"
#include "Parallelogram1.h"
#include "Rhombus1.h"
#include "Rectangle1.h"
#include "Square1.h"



int main()
{
	setlocale(LC_ALL, "ru");

	Figure f;
	f.print_info();

	Triangle t(10, 20, 30, 50, 60, 70);
	Figure* par_tri = &t;
	par_tri->print_info();

	Rec_triangle r(10, 20, 30, 50, 60);
	Figure* par_r = &r;
	par_r->print_info();

	Is_triangle i(10, 20, 50, 60);
	Figure* par_is = &i;
	par_is->print_info();

	Eq_triangle eq(30);
	Figure* par_eq = &eq;
	par_eq->print_info();

	Quadrangle q(10, 20, 30, 40, 90, 70, 120, 80);
	Figure* par_q = &q;
	par_q->print_info();

	Rectangle rec(10, 20);
	Figure* par_rec = &rec;
	par_rec->print_info();

	Rhombus rom(30, 30, 40);
	Figure* par_rom = &rom;
	par_rom->print_info();

	Square sq(20);
	Figure* par_sq = &sq;
	par_sq->print_info();

	Parallelogram par(20, 30, 30, 40);
	Figure* par_par = &par;
	par_par->print_info();


}