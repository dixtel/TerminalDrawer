#ifndef OUTPUT_H
#define OUTPUT_H

#include "include/rectangle.h"
#include "include/text.h"
#include "include/utylitys.h"

#include <iostream>
#include <ncurses.h>

class Output {

public:
    Output(unsigned width, unsigned height, Color clear);

    void Clear();
    Output &operator << (Rectangle &object);
    Output &operator << (Text &object);
    void Draw();

private:
    void SetPixel(PointInt nonfixed_position, Pixel pixel);
    void SetText(PointInt nonfixed_position, std::string text, Color font_color);

    unsigned width;
    unsigned height;
    Color clear;
    Array2D <Pixel> nonfixed_board;
    Array2D <Pixel> fixed_board;
};

#endif // OUTPUT_H
