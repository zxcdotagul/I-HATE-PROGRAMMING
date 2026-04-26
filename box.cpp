#include "box.h"
#include <cstdio>

static int nextId = 1;

Box::Box() : len(10), width(10), height(10), color(0), nameBox(nextId++) {
    calculateVolume();
}

Box::Box(int value) : len(value), width(value), height(value), color(0), nameBox(nextId++) {
    calculateVolume();
}

Box::Box(int len, int width, int height) : len(len), width(width), height(height), color(0), nameBox(nextId++) {
    calculateVolume();
}

void Box::calculateVolume() {
    volume = len * width * height;
}

std::ostream& operator<<(std::ostream& os, const Box& box) {
    os << "[" << box.nameBox << "] = {" << box.height << ", " << box.len << ", " << box.width << "} = " << box.volume;
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