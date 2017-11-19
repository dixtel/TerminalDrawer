#ifndef UTYLITYS_H
#define UTYLITYS_H

#include <assert.h>
#include <string>

struct PointInt {

    int x;
    int y;
};

class Color {

public:
    enum Color_Type {
        Color_Black,
        Color_Red,
        Color_Green,
        Color_Yellow,
        Color_Blue,
        Color_Magneta,
        Color_Cyan,
        Color_White,
        Color_Bright_Black,
        Color_Bright_Red,
        Color_Bright_Green,
        Color_Bright_Yellow,
        Color_Bright_Blue,
        Color_Bright_Magneta,
        Color_Bright_Cyan,
        Color_Bright_White
    };

    Color() {}
    Color(Color_Type c) {color = c;}

    void operator = (Color_Type c) {color = c;}

    std::string GetBackground() {

        switch (color) {
        case Color_Black:
            return "40";
        case Color_Red:
            return "41";
        case Color_Green:
            return "42";
        case Color_Yellow:
            return "43";
        case Color_Blue:
            return "44";
        case Color_Magneta:
            return "45";
        case Color_Cyan:
            return "46";
        case Color_White:
            return "47";
        case Color_Bright_Black:
            return "100";
        case Color_Bright_Red:
            return "101";
        case Color_Bright_Green:
            return "102";
        case Color_Bright_Yellow:
            return "103";
        case Color_Bright_Blue:
            return "104";
        case Color_Bright_Magneta:
            return "105";
        case Color_Bright_Cyan:
            return "106";
        case Color_Bright_White:
            return "107";
        }

        return "";
    }
    std::string GetForeground() {

        switch (color) {
        case Color_Black:
            return "30";
        case Color_Red:
            return "31";
        case Color_Green:
            return "32";
        case Color_Yellow:
            return "33";
        case Color_Blue:
            return "34";
        case Color_Magneta:
            return "35";
        case Color_Cyan:
            return "36";
        case Color_White:
            return "37";
        case Color_Bright_Black:
            return "1;30";
        case Color_Bright_Red:
            return "1;31";
        case Color_Bright_Green:
            return "1;32";
        case Color_Bright_Yellow:
            return "1;33";
        case Color_Bright_Blue:
            return "1;34";
        case Color_Bright_Magneta:
            return "1;35";
        case Color_Bright_Cyan:
            return "1;36";
        case Color_Bright_White:
            return "1;37";
        }

        return "";
    }

private:
    Color_Type color;
};

template <typename T>
class Array {

public:
    Array() {

        lenght = 0;
    }

    Array(unsigned len) {

        lenght = len;
        array = new T [len] ();
    }

    ~Array() {

        delete [] array;
    }

    void SetSize(unsigned len) {

        lenght = len;

        if (array)
            delete array;

        array = new T [len] ();
    }

    T Get(unsigned pos) {

        assert(pos < lenght);
        return array[pos];
    }

    T &operator [] (unsigned pos) {

        assert(pos < lenght);
        return array[pos];
    }

    unsigned Lenght() {

        return lenght;
    }

private:
    T *array = nullptr;
    unsigned lenght;
};

template <typename T>
class Array2D {

public:
    Array2D() {

        width = 0;
        height = 0;
    }

    Array2D(unsigned w, unsigned h) {

        width = w;
        height = h;
        array2d = new T [w * h] ();
    }

    ~Array2D() {

        delete [] array2d;
    }

    void SetSize(unsigned w, unsigned h) {

        width = w;
        height = h;

        if (array2d)
            delete array2d;

        array2d = new T [w * h] ();
    }

    T Get(unsigned x, unsigned y) {

        assert(((x < width) && (y < height)));
        return array2d[y * width + x];
    }

    T &operator () (unsigned x, unsigned y) {

        assert(((x < width) && (y < height)));
        return array2d[y * width + x];
    }

    unsigned Width() {

        return width;
    }

    unsigned Height() {

        return height;
    }

private:
    T *array2d = nullptr;
    unsigned width;
    unsigned height;
};

class Pixel {

public:
    Pixel() {}
    Pixel(Color foreground, Color background, char pixel_word) {Set(foreground, background, pixel_word);}

    void Set(Color foreground, Color background, char pixel_word) {

        this->foreground = foreground;
        this->background = background;
        this->pixel_word = pixel_word;
    }

    Color GetForeground() {return foreground;}
    Color GetBackground() {return background;}
    char GetWord() {return pixel_word;}

private:
    Color foreground;
    Color background;
    char pixel_word;
};

#endif // UTYLITYS_H
