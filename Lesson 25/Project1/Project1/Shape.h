#pragma once
#include <cmath>

enum class ShapeType {
    Line,
    Square,
    Cube,
    Circle,
    Cylinder
};

class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual double getVolume() const = 0;
    virtual void shift(int m, int n, int k) = 0;
    virtual void scaleX(int factor) = 0;
    virtual void scaleY(int factor) = 0;
    virtual void scaleZ(int factor) = 0;
    virtual void scale(int factor) = 0;
};
