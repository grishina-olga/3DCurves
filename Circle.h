#include "Curve.h"

class Circle : public Curve {
public:
    Circle(unsigned int radius);

    void getPoint(double& x, double& y, double& z, double t) override;
    double getFirstDerivative(double t) override;
    std::string getName() override;

    unsigned int getRadius() const;

    ~Circle() override;

private:    
    unsigned int radius;
};