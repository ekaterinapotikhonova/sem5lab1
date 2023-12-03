#ifndef SPHERE_H
#define SPHERE_H

#include "VolumeFigure.h"

class Sphere : public VolumeFigure {
private:
    double radius;

public:
    Sphere(double r);

    void printInfo() const override;
    double calculateArea() const override;
    double calculateVolume() const override;

    void saveToFile(std::ofstream& file) const override;
    static std::unique_ptr<Figure> loadFromFile(std::ifstream& file);
};

#endif