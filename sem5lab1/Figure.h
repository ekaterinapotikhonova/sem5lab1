#ifndef FIGURE_H
#define FIGURE_H

#include <fstream>

class Figure {
public:
    virtual void printInfo() const = 0;
    virtual double calculateArea() const = 0;

    virtual void saveToFile(std::ofstream& file) const = 0;
    static std::unique_ptr<Figure> loadFromFile(std::ifstream& file);

    virtual ~Figure() {}
};

#endif
