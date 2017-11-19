#include "include/rectangle.h"

Rectangle::Rectangle() {

    position = {0, 0};
    width = height = 0;
}

Rectangle::Rectangle(PointInt position, unsigned width, unsigned height, Color::Color_Type color) {

    this->position = position;
    this->width = width;
    this->height = height;
    this->color = color;
}

void Rectangle::SetPosition(PointInt position) {

    this->position = position;
}

void Rectangle::SetSize(unsigned width, unsigned height) {

    this->width = width;
    this->height = height;
}

void Rectangle::SetColor(Color::Color_Type color) {

    this->color = color;
}

PointInt Rectangle::GetPosition() {

    return position;
}

unsigned Rectangle::GetWidth() {

    return width;
}

unsigned Rectangle::GetHeight() {

    return height;
}

Color Rectangle::GetColor() {

    return color;
}
