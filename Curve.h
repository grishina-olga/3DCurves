#pragma once
#include <vector>
#include <string>

class Curve {
public:
    virtual void getPoint(double& x, double& y, double& z, double t) = 0;
    virtual double getFirstDerivative(double t) = 0;
    virtual std::string getName() = 0;
    virtual ~Curve() {};
};
