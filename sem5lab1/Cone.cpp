#include "Cone.h"
#include <iostream>
#include <cmath>

Cone::Cone(double r, double h) : radius(r), height(h) {}

void Cone::printInfo() const {
    std::cout << "Cone with radius: " << radius << " and height: " << height << std::endl;
}

double Cone::calculateArea() const {
    double slant_height = sqrt(radius * radius + height * height);
    return 3.14159 * radius * (radius + slant_height);
}

double Cone::calculateVolume() const {
    return (1.0 / 3.0) * 3.14159 * radius * radius * height;
}

void Cone::saveToFile(std::ofstream& file) const {
    file.write(reinterpret_cast<const char*>(&radius), sizeof(radius));
    file.write(reinterpret_cast<const char*>(&height), sizeof(height));
}

std::unique_ptr<Figure> Cone::loadFromFile(std::ifstream& file) {
    double loadedRadius, loadedHeight;
    file.read(reinterpret_cast<char*>(&loadedRadius), sizeof(loadedRadius));
    file.read(reinterpret_cast<char*>(&loadedHeight), sizeof(loadedHeight));

    return std::make_unique<Cone>(loadedRadius, loadedHeight);
}
