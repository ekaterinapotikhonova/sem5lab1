#ifndef CIRCLE_H
#define CIRCLE_H

#include "FlatFigure.h"

class Circle : public FlatFigure {
private:
    double radius;

public:
    Circle(double r);

    void printInfo() const override;
    double calculateArea() const override;

    void saveToFile(std::ofstream& file) const override;
    static std::unique_ptr<Figure> loadFromFile(std::ifstream& file);
};
#endif

