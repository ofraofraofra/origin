#include <iostream>
#include "Line.h"
#include "Square.h"
#include "Cube.h"
#include "Circle.h"
#include "Cylinder.h"
#include "Transform.h"

int main() {

    setlocale(LC_ALL, "ru");
    system("chcp 1251");

    Line line(0, 0, 1, 1);
    Square square(0, 0, 1, 0, 1, 1, 0, 1);
    Cube cube(0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1);
    Circle circle(0, 0, 1.0);
    Cylinder cylinder(0, 0, 1.0, 2.0);

    Transform tLine(&line);
    Transform tSquare(&square);
    Transform tCube(&cube);
    Transform tCircle(&circle);
    Transform tCylinder(&cylinder);

    std::cout << "������� �����: " << line.getArea() << ", �����: " << line.getVolume() << std::endl;
    std::cout << "������� ��������: " << square.getArea() << ", �����: " << square.getVolume() << std::endl;
    std::cout << "������� ����: " << cube.getArea() << ", �����: " << cube.getVolume() << std::endl;
    std::cout << "������� �����: " << circle.getArea() << ", �����: " << circle.getVolume() << std::endl;
    std::cout << "������� ��������: " << cylinder.getArea() << ", �����: " << cylinder.getVolume() << std::endl;

    tLine.shift(1, 1, 0);
    tSquare.scale(2);
    tCube.scaleX(2);
    tCircle.scaleY(3);
    tCylinder.shift(2, 2, 0);

    std::cout << "����� ��������������:" << std::endl;
    std::cout << "������� �����: " << line.getArea() << ", �����: " << line.getVolume() << std::endl;
    std::cout << "������� ��������: " << square.getArea() << ", �����: " << square.getVolume() << std::endl;
    std::cout << "������� ����: " << cube.getArea() << ", �����: " << cube.getVolume() << std::endl;
    std::cout << "������� �����: " << circle.getArea() << ", �����: " << circle.getVolume() << std::endl;
    std::cout << "������� ��������: " << cylinder.getArea() << ", �����: " << cylinder.getVolume() << std::endl;

    return 0;
}

