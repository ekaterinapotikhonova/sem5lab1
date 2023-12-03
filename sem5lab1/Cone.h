#ifndef CONE_H
#define CONE_H

#include "VolumeFigure.h"

class Cone : public VolumeFigure {
private:
    double radius, height;

public:
    Cone(double r, double h);

    void printInfo() const override;
    double calculateArea() const override;
    double calculateVolume() const override;

    void saveToFile(std::ofstream& file) const override;
    static std::unique_ptr<Figure> loadFromFile(std::ifstream& file);
};

#endif