#include "Triangle.h"
#include <iostream>

Triangle::Triangle(double b, double h) : base(b), height(h) {}

void Triangle::printInfo() const {
    std::cout << "Triangle with base " << base << " and height " << height << ", Area: " << calculateArea() << std::endl;
}

double Triangle::calculateArea() const {
    return 0.5 * base * height;
}

void Triangle::saveToFile(std::ofstream& file) const {
    file << "Triangle with base " << base << " and height " << height << ", Area: " << calculateArea() << std::endl;
}

std::unique_ptr<Figure> Triangle::loadFromFile(std::ifstream& file) {
    double loadedBase, loadedHeight;
    file.read(reinterpret_cast<char*>(&loadedBase), sizeof(loadedBase));
    file.read(reinterpret_cast<char*>(&loadedHeight), sizeof(loadedHeight));

    return std::make_unique<Triangle>(loadedBase, loadedHeight);
}