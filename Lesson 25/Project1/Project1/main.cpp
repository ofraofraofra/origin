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

    std::cout << "Площадь линии: " << line.getArea() << ", объем: " << line.getVolume() << std::endl;
    std::cout << "Площадь квадрата: " << square.getArea() << ", объем: " << square.getVolume() << std::endl;
    std::cout << "Площадь куба: " << cube.getArea() << ", объем: " << cube.getVolume() << std::endl;
    std::cout << "Площадь круга: " << circle.getArea() << ", объем: " << circle.getVolume() << std::endl;
    std::cout << "Площадь цилиндра: " << cylinder.getArea() << ", объем: " << cylinder.getVolume() << std::endl;

    tLine.shift(1, 1, 0);
    tSquare.scale(2);
    tCube.scaleX(2);
    tCircle.scaleY(3);
    tCylinder.shift(2, 2, 0);

    std::cout << "После преобразований:" << std::endl;
    std::cout << "Площадь линии: " << line.getArea() << ", объем: " << line.getVolume() << std::endl;
    std::cout << "Площадь квадрата: " << square.getArea() << ", объем: " << square.getVolume() << std::endl;
    std::cout << "Площадь куба: " << cube.getArea() << ", объем: " << cube.getVolume() << std::endl;
    std::cout << "Площадь круга: " << circle.getArea() << ", объем: " << circle.getVolume() << std::endl;
    std::cout << "Площадь цилиндра: " << cylinder.getArea() << ", объем: " << cylinder.getVolume() << std::endl;

    return 0;
}

