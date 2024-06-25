#include "Transform.h"

Transform::Transform(Shape* sh) : shape(sh) {}

void Transform::shift(int m, int n, int k) {
    shape->shift(m, n, k);
}

void Transform::scaleX(int factor) {
    shape->scaleX(factor);
}

void Transform::scaleY(int factor) {
    shape->scaleY(factor);
}

void Transform::scaleZ(int factor) {
    shape->scaleZ(factor);
}

void Transform::scale(int factor) {
    shape->scale(factor);
}