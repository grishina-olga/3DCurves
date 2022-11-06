#include "Circle.h"
#include <cmath>

Circle::Circle(unsigned int radius) {
    this->radius = radius;
}

void Circle::getPoint(double& x, double& y, double& z, double t) {
    x = this->radius * cos(t);
    y = this->radius * sin(t);
    z = 0;
}

// x'(t) = -radius * sin(t)
// y'(t) = radius * cos(t)
// y'(x) = -1/tan(t)
double Circle::getFirstDerivative(double t) {
    return -1/tan(t);
}

std::string Circle::getName() {
    return "Circle";
}

unsigned int Circle::getRadius() const {
    return this->radius;
}

Circle::~Circle() {};