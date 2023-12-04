#include "RectangularPrism.h"
#include <iostream>

RectangularPrism::RectangularPrism(double l, double w, double h) : length(l), width(w), height(h) {}

void RectangularPrism::printInfo() const {
    std::cout << "Rectangular Prism with length " << length << ", width " << width << ", and height " << height << ", Volume: " << calculateVolume() << std::endl;
}

double RectangularPrism::calculateArea() const {
    return 2.0 * (length * width + length * height + width * height);
}

double RectangularPrism::calculateVolume() const {
    return length * width * height;
}

void RectangularPrism::saveToFile(std::ofstream& file) const {
    file << "RectangularPrism with length " << length << ", width " << width << " and height " << height << ", Volume: " << calculateVolume() << std::endl;
}

std::unique_ptr<Figure> RectangularPrism::loadFromFile(std::ifstream& file) {
    double loadedLength, loadedWidth, loadedHeight;
    file.read(reinterpret_cast<char*>(&loadedLength), sizeof(loadedLength));
    file.read(reinterpret_cast<char*>(&loadedWidth), sizeof(loadedWidth));
    file.read(reinterpret_cast<char*>(&loadedHeight), sizeof(loadedHeight));

    return std::make_unique<RectangularPrism>(loadedLength, loadedWidth, loadedHeight);
}