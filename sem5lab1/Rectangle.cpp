#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double a, double b) : sideA(a), sideB(b) {}

void Rectangle::printInfo() const {
    std::cout << "Rectangle with sides: " << sideA << " and " << sideB << std::endl;
}

double Rectangle::calculateArea() const {
    return sideA * sideB;
}

void Rectangle::saveToFile(std::ofstream& file) const {
    file.write(reinterpret_cast<const char*>(&sideA), sizeof(sideA));
    file.write(reinterpret_cast<const char*>(&sideB), sizeof(sideB));
}

std::unique_ptr<Figure> Rectangle::loadFromFile(std::ifstream& file) {
    double loadedSideA, loadedSideB;
    file.read(reinterpret_cast<char*>(&loadedSideA), sizeof(loadedSideA));
    file.read(reinterpret_cast<char*>(&loadedSideB), sizeof(loadedSideB));

    return std::make_unique<Rectangle>(loadedSideA, loadedSideB);
}
