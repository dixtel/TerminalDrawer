#include "include/output.h"

Output::Output(unsigned width, unsigned height, Color clear) {

    this->width = width;
    this->height = height;
    this->clear = clear;

    nonfixed_board.SetSize(width, height);
    fixed_board.SetSize(width * 2, height);
    Clear();
}

void Output::Clear() {

    for(int y = 0; y < fixed_board.Height(); ++y) {
        for(int x = 0; x < fixed_board.Width(); ++x) {

            fixed_board(x, y) = Pixel(clear, clear, ' ');
        }
    }

    for(int y = 0; y < nonfixed_board.Height(); ++y) {
        for(int x = 0; x < nonfixed_board.Width(); ++x) {

            nonfixed_board(x, y) = Pixel(clear, clear, ' ');
        }
    }
}

Output &Output::operator << (Rectangle &object) {

    for(int y = 0; y < object.GetHeight(); ++y) {
        for(int x = 0; x < object.GetWidth(); ++x) {

            PointInt pos = {object.GetPosition().x + x, object.GetPosition().y + y};
            SetPixel(pos, Pixel(object.GetColor(), object.GetColor(), ' '));
        }
    }

    return *this;
}

Output &Output::operator << (Text &object) {

    SetText(object.GetPosition(), object.GetText(), object.GetFontColor());

    return *this;
}

void Output::Draw() {

    for(int y = 0; y < fixed_board.Height(); ++y) {
        for(int x = 0; x < fixed_board.Width(); ++x) {

            Pixel curr_pxl = fixed_board.Get(x, y);

            std::string foreground = curr_pxl.GetForeground().GetForeground();
            std::string background = curr_pxl.GetBackground().GetBackground();

            char word = curr_pxl.GetWord();

            std::string formula = "\033[" + foreground + ";" + background + "m" + word + "\033[0m";

            std::string ch;
            ch += curr_pxl.GetWord();
            move(y, x);
            init_pair(1, COLOR_BLUE, COLOR_GREEN);
            attron(COLOR_PAIR(1));
            printw(ch.c_str());
            //std::cout << formula;
        }

        //std::cout << std::endl;
    }
    refresh();
}

void Output::SetPixel(PointInt nonfixed_position, Pixel pixel) {

    PointInt fixed_position = {nonfixed_position.x * 2, nonfixed_position.y};

    if ((fixed_position.x >= 0) && (fixed_position.x < width * 2) && (fixed_position.y >= 0) && (fixed_position.y < height)) {

        fixed_board(fixed_position.x, fixed_position.y) = pixel;
        fixed_board(fixed_position.x + 1, fixed_position.y) = pixel;
    }

}

void Output::SetText(PointInt nonfixed_position, std::string text, Color font_color) {

    PointInt fixed_position = {nonfixed_position.x * 2, nonfixed_position.y};

    for(int i = 0; i < text.size(); ++i) {
       if ((fixed_position.x >= 0) && (fixed_position.x < width * 2) && (fixed_position.y >= 0) && (fixed_position.y < height))
           fixed_board(fixed_position.x, fixed_position.y).Set(font_color,
                                                               fixed_board(fixed_position.x, fixed_position.y).GetBackground(),
                                                               text[i]);
        fixed_position.x++;
    }
}
