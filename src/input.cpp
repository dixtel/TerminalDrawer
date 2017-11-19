#include "include/input.h"

Input::Input() {

}

Input::~Input() {

}

int Input::GetChar() {

    int c = getch();

    if (c != ERR)
        return c;

    return ERR;

}
