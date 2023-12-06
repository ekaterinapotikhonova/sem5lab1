#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "FlatFigure.h"

class Triangle : public FlatFigure {
private:
    double sideA, sideB, sideC;

public:
    Triangle(double a, double b, double c);

    bool isValidTriangle() const;

    void printInfo() const override;
    double calculateArea() const override;

    void saveToFile(std::ofstream& file) const override;
    static std::unique_ptr<Figure> loadFromFile(std::ifstream& file);
};

#endif