#include "Keeper.h"
#include <fstream>
#include <iostream>

Keeper::Keeper() {}

Keeper::~Keeper() {}

void Keeper::addFigure(std::unique_ptr<Figure> figure) {
    figures.push_back(std::move(figure));
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        size_t count = figures.size();
        file.write(reinterpret_cast<const char*>(&count), sizeof(count));

        for (const auto& figure : figures) {
            figure->saveToFile(file);
        }

        std::cout << "Figures saved to file: " << filename << std::endl;
    }
    else {
        std::cerr << "Error opening file for writing: " << filename << std::endl;
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
        figures.clear();

        size_t count;
        file.read(reinterpret_cast<char*>(&count), sizeof(count));

        for (size_t i = 0; i < count; ++i) {
            std::unique_ptr<Figure> figure = Figure::loadFromFile(file);
            if (figure) {
                figures.push_back(std::move(figure));
            }
        }

        std::cout << "Figures loaded from file: " << filename << std::endl;
    }
    else {
        std::cerr << "Error opening file for reading: " << filename << std::endl;
    }
}

void Keeper::printAllFiguresInfo() const {
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i + 1 << ":\n";
        figures[i]->printInfo();
    }
}

void Keeper::removeFigure(int index) {
    if (index >= 0 && index < figures.size()) {
        figures.erase(figures.begin() + index);
    }
}

int Keeper::getFigureCount() const {
    return figures.size();
}