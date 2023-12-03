#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "FlatFigure.h"

class Rectangle : public FlatFigure {
private:
    double sideA, sideB;

public:
    Rectangle(double a, double b);

    void printInfo() const override;
    double calculateArea() const override;

    void saveToFile(std::ofstream& file) const override;
    static std::unique_ptr<Figure> loadFromFile(std::ifstream& file);
};

#endif
