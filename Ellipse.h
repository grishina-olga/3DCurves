#include "Curve.h"

class Ellipse : public Curve {
public:
    Ellipse(unsigned int radiusX, unsigned int radiusY);

    void getPoint(double& x, double& y, double& z, double t) override;
    double getFirstDerivative(double t) override;
    std::string getName() override;

    ~Ellipse() override;

private:    
    unsigned int radiusX;
    unsigned int radiusY;
};