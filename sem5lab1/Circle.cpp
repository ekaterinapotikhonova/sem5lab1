#include "Circle.h"
#include <iostream>

Circle::Circle(double r) : radius(r) {}

void Circle::printInfo() const {
    std::cout << "Circle with radius: " << radius << std::endl;
}

double Circle::calculateArea() const {
    return 3.14159 * radius * radius;
}

void Circle::saveToFile(std::ofstream& file) const {
    file.write(reinterpret_cast<const char*>(&radius), sizeof(radius));
}

std::unique_ptr<Figure> Circle::loadFromFile(std::ifstream& file) {
    double loadedRadius;
    file.read(reinterpret_cast<char*>(&loadedRadius), sizeof(loadedRadius));

    return std::make_unique<Circle>(loadedRadius);
}
