#include "rk_1..h"
#include <cstdlib>  

// без параметров
Box::Box() {
    _len = 10;
    _width = 10;
    _height = 10;
    _color = 0;
    _volume = abs(_len * _width * _height);
}

// 1 параметр
Box::Box(int value) {
    _len = value;
    _width = value;
    _height = value;
    _color = 0;
    _volume = abs(_len * _width * _height);
}

// 3 параметра
Box::Box(int len, int width, int height) {
    _len = len;
    _width = width;
    _height = height;
    _color = 0;
    _volume = abs(_len * _width * _height);
}


std::ostream& operator<<(std::ostream& os, const Box& box) {
    os << "len = " << box._len
        << ", width = " << box._width
        << ", height = " << box._height
        << ", volume = " << box._volume << "\n";
    return os;
}