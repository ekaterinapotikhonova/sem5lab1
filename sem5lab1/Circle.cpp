// Circle.cpp

#include "Circle.h"
#include <iostream>

Circle::Circle(double radius) : radius(radius) {}

void Circle::printInfo() const {
    std::cout << "Circle with radius " << radius << ", Area: " << calculateArea() << std::endl;
}

double Circle::calculateArea() const {
    return 3.14159 * radius * radius;
}

void Circle::saveToFile(std::ofstream& file) const {
    file << "Circle with radius " << radius << ", Area: " << calculateArea() << std::endl;
}

std::unique_ptr<Figure> Circle::loadFromFile(std::ifstream& file) {
    double loadedRadius;
    file >> loadedRadius;
    return std::make_unique<Circle>(loadedRadius);
}

