#ifndef INPUT_H
#define INPUT_H

#include <ncurses.h>
#include <iostream>

const char EMPTY_CHAR = char(0);

class Input {

public:    
    Input();
    ~Input();

    int GetChar();
};

#endif // INPUT_H
