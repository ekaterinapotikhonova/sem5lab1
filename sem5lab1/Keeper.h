#ifndef KEEPER_H
#define KEEPER_H

#include <vector>
#include <memory>
#include "Figure.h"

class Keeper {
public:
    Keeper();
    ~Keeper();

    void addFigure(std::unique_ptr<Figure> figure);
    int getFigureCount() const;
    void removeFigure(int index);

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

    void printAllFiguresInfo() const;

private:
    std::vector<std::unique_ptr<Figure>> figures;
};

#endif