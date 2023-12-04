#include "Keeper.h"
#include <fstream>
#include <iostream>

Keeper::Keeper() : capacity(10), size(0), figures(new std::unique_ptr<Figure>[capacity]) {}

Keeper::~Keeper() {
    // Обеспечиваем автоматическое удаление объектов при удалении std::unique_ptr
}

void Keeper::addFigure(std::unique_ptr<Figure> figure) {
    if (size == capacity) {
        resize();
    }
    figures[size++] = std::move(figure);
}

void Keeper::printAllFiguresInfo() const {
    for (int i = 0; i < size; ++i) {
        figures[i]->printInfo();
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file for writing.\n";
        return;
    }

    file.write(reinterpret_cast<const char*>(&size), sizeof(size));
    for (int i = 0; i < size; ++i) {
        figures[i]->saveToFile(file);
    }

    file.close();
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file for reading.\n";
        return;
    }

    file.read(reinterpret_cast<char*>(&size), sizeof(size));
    if (size > capacity) {
        figures = std::make_unique<std::unique_ptr<Figure>[]>(size);
        capacity = size;
    }

    for (int i = 0; i < size; ++i) {
        figures[i] = Figure::loadFromFile(file);
    }

    file.close();
}

void Keeper::removeFigure(int index) {
    if (index >= 0 && index < size) {
        for (int i = index; i < size - 1; ++i) {
            figures[i] = std::move(figures[i + 1]);
        }
        --size;
    }
}

int Keeper::getFigureCount() const {
    return size;
}

void Keeper::resize() {
    capacity *= 2;
    auto newFigures = std::make_unique<std::unique_ptr<Figure>[]>(capacity);
    for (int i = 0; i < size; ++i) {
        newFigures[i] = std::move(figures[i]);
    }
    figures = std::move(newFigures);
}
