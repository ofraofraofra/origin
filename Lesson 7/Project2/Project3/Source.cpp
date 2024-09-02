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
#include "Exeption.h"



int main()
{
	setlocale(LC_ALL, "ru");

		try {
			Triangle t(10, 20, 30, 50, 60, 70);
			Figure* par_tri = &t;
			par_tri->print_info();

			Rec_triangle r(10, 20, 30, 50, 40, 90);
			Figure* par_r = &r;
			par_r->print_info();

			Is_triangle i(10, 20, 10, 70, 40, 70);
			Figure* par_is = &i;
			par_is->print_info();

			Eq_triangle eq(30, 30, 30, 60, 60, 60);
			Figure* par_eq = &eq;
			par_eq->print_info();

			Quadrangle q(10, 20, 30, 40, 90, 70, 120, 80);
			Figure* par_q = &q;
			par_q->print_info();

			Parallelogram par(20, 30, 20, 30, 100, 80, 100, 80);
			Figure* par_par = &par;
			par_par->print_info();

			Rectangle rec(20, 30, 20, 30, 90, 90, 90, 90);
			Figure* par_rec = &rec;
			par_rec->print_info();

			Rhombus rom(30, 30, 30, 30, 80, 100, 80, 100);
			Figure* par_rom = &rom;
			par_rom->print_info();

			Square sq(30, 30, 30, 30, 90, 90, 90, 90);
			Figure* par_sq = &sq;
			par_sq->print_info();

			/*
			
			Triangle t1(10, 20, 30, 50, 60, 60);
			Figure* par_tri1 = &t1;
			par_tri1->print_info();

			Rec_triangle r1(10, 20, 30, 40, 60, 80);
			Figure* par_r1 = &r1;
			par_r1->print_info();

			Is_triangle i1(10, 20, 10, 60, 40, 80);
			Figure* par_is1 = &i1;
			par_is1->print_info();

			Is_triangle i2(10, 20, 20, 80, 20, 80);
			Figure* par_is2 = &i2;
			par_is2->print_info();

			Eq_triangle eq1(20, 30, 30, 60, 60, 60);
			Figure* par_eq1 = &eq1;
			par_eq1->print_info();

			Eq_triangle eq2(30, 30, 30, 50, 50, 80);
			Figure* par_eq2 = &eq2;
			par_eq2->print_info();

			Quadrangle q1(10, 20, 30, 40, 90, 70, 120, 90);
			Figure* par_q1 = &q1;
			par_q1->print_info();

			Parallelogram par1(20, 30, 30, 30, 100, 80, 100, 80);
			Figure* par_par1 = &par1;
			par_par1->print_info();

			Parallelogram par2(20, 30, 20, 30, 110, 80, 90, 80);
			Figure* par_par2 = &par2;
			par_par2->print_info();

			Rectangle rec1(20, 30, 30, 30, 90, 90, 90, 90);
			Figure* par_rec1 = &rec1;
			par_rec1->print_info();

			Rectangle rec2(20, 30, 20, 30, 90, 100, 80, 90);
			Figure* par_rec2 = &rec2;
			par_rec2->print_info();

			Rhombus rom1(30, 20, 30, 30, 80, 100, 80, 100);
			Figure* par_rom1 = &rom1;
			par_rom1->print_info();

			Rhombus rom2(30, 30, 30, 30, 70, 100, 90, 100);
			Figure* par_rom2 = &rom2;
			par_rom2->print_info();

			Square sq1(30, 20, 30, 20, 90, 90, 90, 90);
			Figure* par_sq1 = &sq1;
			par_sq1->print_info();

			Square sq2(30, 30, 30, 30, 100, 80, 100, 80);
			Figure* par_sq2 = &sq2;
			par_sq2->print_info();

			*/				
		}
		catch (const std::exception& ex) {
			std::cout << ex.what() << std::endl;
		}		
}
