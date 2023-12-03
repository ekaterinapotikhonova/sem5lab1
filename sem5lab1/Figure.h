#pragma once

class Figure {
public:
    virtual ~Figure() {}

    virtual void display() const = 0;
    
};
