#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "include/utylitys.h"

class Rectangle {

public:
    Rectangle();
    Rectangle(PointInt position, unsigned width, unsigned height, Color::Color_Type color);

    void SetPosition(::PointInt position);
    void SetSize(unsigned width, unsigned height);
    void SetColor(Color::Color_Type color);

    PointInt GetPosition();
    unsigned GetWidth();
    unsigned GetHeight();
    Color GetColor();

private:
    PointInt position;
    unsigned width;
    unsigned height;
    Color color;
};

#endif // RECTANGLE_H
