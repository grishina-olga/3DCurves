#include "Curve.h"

class Helix : public Curve {
public:
    Helix(unsigned int radius, unsigned int step);

    void getPoint(double& x, double& y, double& z, double t) override;
    double getFirstDerivative(double t) override;
    std::string getName() override;

    ~Helix() override;

private:    
    unsigned int radius;
    unsigned int step;
};