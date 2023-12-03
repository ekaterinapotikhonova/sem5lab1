#pragma once
#include <vector>

class Keeper {
public:
    Keeper();

    void addFigure(Figure* figure);
    void removeFigure(int index);
    void displayFigures() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);

private:
    std::vector<Figure*> figures;
};
