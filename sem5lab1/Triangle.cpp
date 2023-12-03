#include "Triangle.h"
#include <iostream>

Triangle::Triangle(double b, double h) : base(b), height(h) {}

void Triangle::printInfo() const {
    std::cout << "Triangle with base: " << base << " and height: " << height << std::endl;
}

double Triangle::calculateArea() const {
    return 0.5 * base * height;
}

void Triangle::saveToFile(std::ofstream& file) const {
    file.write(reinterpret_cast<const char*>(&base), sizeof(base));
    file.write(reinterpret_cast<const char*>(&height), sizeof(height));
}

std::unique_ptr<Figure> Triangle::loadFromFile(std::ifstream& file) {
    double loadedBase, loadedHeight;
    file.read(reinterpret_cast<char*>(&loadedBase), sizeof(loadedBase));
    file.read(reinterpret_cast<char*>(&loadedHeight), sizeof(loadedHeight));

    return std::make_unique<Triangle>(loadedBase, loadedHeight);
}