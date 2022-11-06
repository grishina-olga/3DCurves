#include "Helix.h"
#include <cmath>

Helix::Helix(unsigned int radius, unsigned int step) {
    this->radius = radius;
    this->step = step;
}

void Helix::getPoint(double& x, double& y, double& z, double t) {
    x = this->radius * cos(t);
    y = this->radius * sin(t);
    z = this->step * t;
}

// x'(t) = -radius * sin(t)
// y'(t) = radius * cos(t)
// z'(t) = step
// z'(x) = -step/(radius * sin(t))
// z'(y) = step/(radius * cos(t))
// z'(x, y) = z'(x) + z'(y)
double Helix::getFirstDerivative(double t) {
    return (this->step/this->radius) * ((sin(t) - cos(t))/(cos(t) * sin(t)));
}

std::string Helix::getName() {
    return "Helix";
}

Helix::~Helix() {};