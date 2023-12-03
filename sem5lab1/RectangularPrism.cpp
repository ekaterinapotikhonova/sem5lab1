#include "RectangularPrism.h"
#include <iostream>

RectangularPrism::RectangularPrism(double l, double w, double h) : length(l), width(w), height(h) {}

void RectangularPrism::printInfo() const {
    std::cout << "Rectangular Prism with length: " << length << ", width: " << width << ", and height: " << height << std::endl;
}

double RectangularPrism::calculateArea() const {
    return 2.0 * (length * width + length * height + width * height);
}

double RectangularPrism::calculateVolume() const {
    return length * width * height;
}

void RectangularPrism::saveToFile(std::ofstream& file) const {
    file.write(reinterpret_cast<const char*>(&length), sizeof(length));
    file.write(reinterpret_cast<const char*>(&width), sizeof(width));
    file.write(reinterpret_cast<const char*>(&height), sizeof(height));
}

std::unique_ptr<Figure> RectangularPrism::loadFromFile(std::ifstream& file) {
    double loadedLength, loadedWidth, loadedHeight;
    file.read(reinterpret_cast<char*>(&loadedLength), sizeof(loadedLength));
    file.read(reinterpret_cast<char*>(&loadedWidth), sizeof(loadedWidth));
    file.read(reinterpret_cast<char*>(&loadedHeight), sizeof(loadedHeight));

    return std::make_unique<RectangularPrism>(loadedLength, loadedWidth, loadedHeight);
}