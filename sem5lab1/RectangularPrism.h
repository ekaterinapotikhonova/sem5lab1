#ifndef RECTANGULARPRISM_H
#define RECTANGULARPRISM_H

#include "VolumeFigure.h"

class RectangularPrism : public VolumeFigure {
private:
    double length, width, height;

public:
    RectangularPrism(double l, double w, double h);

    void printInfo() const override;
    double calculateArea() const override;
    double calculateVolume() const override;

    void saveToFile(std::ofstream& file) const override;
    static std::unique_ptr<Figure> loadFromFile(std::ifstream& file);
};

#endif