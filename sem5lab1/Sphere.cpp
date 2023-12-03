#include "Sphere.h"
#include <iostream>

Sphere::Sphere(double r) : radius(r) {}

void Sphere::printInfo() const {
    std::cout << "Sphere with radius: " << radius << std::endl;
}

double Sphere::calculateArea() const {
    return 4.0 * 3.14159 * radius * radius;
}

double Sphere::calculateVolume() const {
    return (4.0 / 3.0) * 3.14159 * radius * radius * radius;
}

void Sphere::saveToFile(std::ofstream& file) const {
    file.write(reinterpret_cast<const char*>(&radius), sizeof(radius));
}

std::unique_ptr<Figure> Sphere::loadFromFile(std::ifstream& file) {
    double loadedRadius;
    file.read(reinterpret_cast<char*>(&loadedRadius), sizeof(loadedRadius));

    return std::make_unique<Sphere>(loadedRadius);
}