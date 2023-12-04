#include "Figure.h"

std::unique_ptr<Figure> Figure::loadFromFile(std::ifstream& file) {
    // This function is pure virtual in the base class,
    // and it needs to be implemented in each derived class.
    // Each derived class knows how to read its own data from the file.
    return nullptr;
}