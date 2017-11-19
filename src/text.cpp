#include "include/text.h"

Text::Text() {

    position = {0, 0};
    font_color = Color::Color_White;
}

Text::Text(PointInt position, std::string text) {

    this->position = position;
    this->text = text;
}

Text::Text(PointInt position, std::string text, Color font_color) {

    this->position = position;
    this->text = text;
    this->font_color = font_color;
}

void Text::SetPosition(PointInt position) {

    this->position = position;
}

void Text::SetText(std::string text) {

    this->text = text;
}

void Text::SetFontColor(Color font_color) {

    this->font_color = font_color;
}

PointInt Text::GetPosition() {

    return position;
}

std::string Text::GetText()  {

    return text;
}

Color Text::GetFontColor() {

    return font_color;
}
