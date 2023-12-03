#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "FlatFigure.h"

class Triangle : public FlatFigure {
private:
    double base, height;

public:
    Triangle(double b, double h);

    void printInfo() const override;
    double calculateArea() const override;

    void saveToFile(std::ofstream& file) const override;
    static std::unique_ptr<Figure> loadFromFile(std::ifstream& file);
};

#endif