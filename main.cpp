#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

#include <omp.h>

#define PI 3.14159265

int main()
{
    std::vector<std::shared_ptr<Curve>> curves;

    int numOfCurves = 2000;
    for (int i = 0; i < numOfCurves; i++) {
        switch (rand() % 3) {
            case 0:
                curves.push_back(std::make_shared<Circle>(rand()));
                break;
            case 1:
                curves.push_back(std::make_shared<Ellipse>(rand(), rand()));
                break;
            case 2:
                curves.push_back(std::make_shared<Helix>(rand(), rand()));
                break;
        }
    }
    
    for (auto curve : curves) {
        std::cout<<curve->getName()<<":"<<std::endl;
        double x, y, z;
        curve->getPoint(x, y, z, PI/4);
        std::cout<<"3D point: x = "<<x<<", y = "<<y<<", z = "<<z<<std::endl;
        double der = curve->getFirstDerivative(PI/4);
        std::cout<<"Firts derivative: "<<der<<std::endl<<std::endl;
    }

    std::vector<std::shared_ptr<Circle>> circles;
    for (auto curve : curves) {
        if (curve->getName() == "Circle") {
            circles.push_back(std::dynamic_pointer_cast<Circle>(curve));
        }
    }
    std::cout<<std::endl;

    std::sort(circles.begin(), circles.end(),
    [] (const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) {
        return (*a).getRadius() < (*b).getRadius();
    });
    
    
    omp_set_num_threads(4);
    long long int sumOfCirclesRadius = 0;
    #pragma omp parallel for
    for (auto circle : circles) {
        sumOfCirclesRadius += circle->getRadius();
    }
    std::cout<<"Sum of circles radiuses: "<<sumOfCirclesRadius<<std::endl;

    return 0;
}
