#include "include/rectangle.h"
#include "include/output.h"
#include "include/input.h"

#include <iostream>
#include <ncurses.h>

int main() {

    // TODO move this to init function
    initscr();
    start_color();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    Output op(20, 10, Color::Color_Blue);
    Input in;
    Rectangle rect_1(::PointInt{3, 5}, 1, 5, Color::Color_Black);
    Rectangle rect_2(::PointInt{4, 5}, 1, 5, Color::Color_Cyan);
    Rectangle rect_3(::PointInt{5, 5}, 1, 5, Color::Color_Green);
    Text text_1(::PointInt{3, 4}, "1", Color::Color_Bright_Yellow);
    Text text_2(::PointInt{4, 4}, "2");
    Text text_3(::PointInt{5, 4}, "3");


    for(;;) {

        int event = in.GetChar();

        if (event == 'e')
            break;
        else if (event == KEY_LEFT)
            rect_1.SetPosition(PointInt{rect_1.GetPosition().x - 1, rect_1.GetPosition().y});
        else if (event == KEY_RIGHT)
            rect_1.SetPosition(PointInt{rect_1.GetPosition().x + 1, rect_1.GetPosition().y});

        op.Clear();
        op << rect_1 << rect_2 << rect_3;
        op << text_1 << text_2 << text_3;
        op.Draw();
    }

    endwin();

    return 0;
}
