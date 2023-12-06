#include "Triangle.h"
#include <iostream>

Triangle::Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {
    while (true) {
        std::cout << "Enter side A: ";
        std::cin >> sideA;
        std::cout << "Enter side B: ";
        std::cin >> sideB;
        std::cout << "Enter side C: ";
        std::cin >> sideC;

        if (isValidTriangle()) {
            break;
        }

        std::cout << "Invalid sides for a triangle. Please enter valid values." << std::endl;
    }
}

bool Triangle::isValidTriangle() const {
    return ((sideA + sideB) > sideC) && ((sideA + sideC) > sideB) && ((sideB + sideC) > sideA);
}

void Triangle::printInfo() const {
    std::cout << "Triangle with sides " << sideA << ", " << sideB << ", " << sideC << ", Area: " << calculateArea() << std::endl;
}

double Triangle::calculateArea() const {
    return sqrt(((sideA + sideB + sideC) / 2) * (((sideA + sideB + sideC) / 2) - sideA) * (((sideA + sideB + sideC) / 2) - sideB) * (((sideA + sideB + sideC) / 2) - sideC));
}

void Triangle::saveToFile(std::ofstream& file) const {
    file << "Triangle with sides " << sideA << ", " << sideB << ", " << sideC << ", Area: " << calculateArea() << std::endl;
}

std::unique_ptr<Figure> Triangle::loadFromFile(std::ifstream& file) {
    double loadedSideA, loadedSideB, loadedSideC;
    file.read(reinterpret_cast<char*>(&loadedSideA), sizeof(loadedSideA));
    file.read(reinterpret_cast<char*>(&loadedSideB), sizeof(loadedSideB));
    file.read(reinterpret_cast<char*>(&loadedSideC), sizeof(loadedSideC));

    return std::make_unique<Triangle>(loadedSideA, loadedSideB, loadedSideC);
}