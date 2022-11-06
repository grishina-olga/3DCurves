#include "Ellipse.h"
#include <cmath>

Ellipse::Ellipse(unsigned int radiusX, unsigned int radiusY) {
    this->radiusX = radiusX;
    this->radiusY = radiusY;
}

void Ellipse::getPoint(double& x, double& y, double& z, double t) {
    x = this->radiusX * cos(t);
    y = this->radiusY * sin(t);
    z = 0;
}

// x'(t) = -radiusX * sin(t)
// y'(t) = radiusY * cos(t)
// y'(x) = -radiusY/(radiusX * tan(t))
double Ellipse::getFirstDerivative(double t) {
    return -radiusY/(radiusX*tan(t));
}

std::string Ellipse::getName() {
    return "Ellipse";
}

Ellipse::~Ellipse() {};