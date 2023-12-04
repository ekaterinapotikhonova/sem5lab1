#include "Keeper.h"
#include <fstream>
#include <iostream>
#include <string>

Keeper::Keeper() : capacity(10), size(0), figures(new std::unique_ptr<Figure>[capacity]) {}

Keeper::~Keeper() {}

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
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file for writing.\n";
        return;
    }

    file << "Total Figures: " << size << std::endl;

    for (int i = 0; i < size; ++i) {
        file << "Figure " << i + 1 << ":" << std::endl;
        figures[i]->saveToFile(file);
        file << std::endl;
    }

    file.close();
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file for reading.\n";
        return;
    }

    // Добавим пропуск строки с общим количеством фигур
    std::string line;
    std::getline(file, line);
    std::cout << line << std::endl; // Выводим для проверки

    // Пропустим строки с метками "Figure N:"
    while (std::getline(file, line)) {
        if (line.find("Figure") == std::string::npos) {
            continue;
        }

        std::cout << line << std::endl; // Выводим для проверки

        // Разбираем строку, чтобы получить номер фигуры
        int figureNumber;
        sscanf_s(line.c_str(), "Figure %d:", &figureNumber);

        // Создаем фигуру
        std::unique_ptr<Figure> loadedFigure = Figure::loadFromFile(file);
        if (loadedFigure) {
            addFigure(std::move(loadedFigure));
        }
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
