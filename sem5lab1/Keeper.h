#ifndef KEEPER_H
#define KEEPER_H

#include "Figure.h"
#include <memory>

class Keeper {
public:
    Keeper();
    ~Keeper();

    void addFigure(std::unique_ptr<Figure> figure);
    void printAllFiguresInfo() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void removeFigure(int index);
    int getFigureCount() const;

private:
    void resize();

    int capacity;
    int size;
    std::unique_ptr<std::unique_ptr<Figure>[]> figures;
};

#endif // KEEPER_H