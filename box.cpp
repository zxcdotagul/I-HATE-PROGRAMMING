#include "box.h"
#include <cstdio>

static int nextId = 1;

Box::Box() : _len(10), _width(10), _height(10), _color(0), _nameBox(nextId++) {
    calculateVolume();
}

Box::Box(int value) : _len(value), _width(value), _height(value), _color(0), _nameBox(nextId++) {
    calculateVolume();
}

Box::Box(int len, int width, int height) : _len(len), _width(width), _height(height), _color(0), _nameBox(nextId++) {
    calculateVolume();
}

void Box::calculateVolume() {
    _volume = _len * _width * _height;
}
std::ostream& operator<<(std::ostream& os, const Box& box);
std::ostream& operator<<(std::ostream& os, const Box& box) {
    os << "[" << box._nameBox << "] = {" << box._height << ", " << box._len << ", " << box._width << "} = " << box._volume;
    return os;
}

void writeToFile(const char* fileName, const struct Box& box) {
    FILE* file = fopen(fileName, "wb");
    if (file != nullptr) {
        fwrite(&box, sizeof(Box), 1, file);
        fclose(file);
    }
}

void readFromFile(const char* fileName, struct Box* box) {
    if (fileName == nullptr || box == nullptr) {
        return;
    }
    FILE* file = fopen(fileName, "rb");
    if (file != nullptr) {
        fread(box, sizeof(Box), 1, file);
        fclose(file);
    }
}


void readFromFile(const char* fileName, Box& box) {
    readFromFile(fileName, &box);
}