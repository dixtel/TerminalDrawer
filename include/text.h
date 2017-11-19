#ifndef TEXT_H
#define TEXT_H

#include "include/utylitys.h"

#include <string>

class Text {

public:
    Text();
    Text(PointInt position, std::string text);
    Text(PointInt position, std::string text, Color font_color);

    void SetPosition(::PointInt position);
    void SetText(std::string text);
    void SetFontColor(Color font_color);

    PointInt GetPosition();
    std::string GetText();
    Color GetFontColor();

private:
    PointInt position;
    std::string text;
    Color font_color;
};

#endif // TEXT_H
