#ifndef VOLUMEFIGURE_H
#define VOLUMEFIGURE_H

#include "Figure.h"

class VolumeFigure : public Figure {
public:
    virtual double calculateVolume() const = 0;

    virtual void saveToFile(std::ofstream& file) const override = 0;
    static std::unique_ptr<VolumeFigure> loadFromFile(std::ifstream& file);

    virtual ~VolumeFigure() {}
};

#endif
