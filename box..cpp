#include "box.h"
#include <fstream>
#include <iostream>

void writeToFile(const char* fileName, const struct Box& box) {
    std::ofstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        return; 
    }

    file.write(reinterpret_cast<const char*>(&box._len), sizeof(box._len));
    file.write(reinterpret_cast<const char*>(&box._width), sizeof(box._width));
    file.write(reinterpret_cast<const char*>(&box._height), sizeof(box._height));
    file.write(reinterpret_cast<const char*>(&box._color), sizeof(box._color));

    file.close();
}

void readFromFile(const char* fileName, struct Box& box) {
    if (&box == nullptr) {
        return;
    }

    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) {
        return;
    }

    file.read(reinterpret_cast<char*>(&box._len), sizeof(box._len));
    file.read(reinterpret_cast<char*>(&box._width), sizeof(box._width));
    file.read(reinterpret_cast<char*>(&box._height), sizeof(box._height));
    file.read(reinterpret_cast<char*>(&box._color), sizeof(box._color));

    file.close();
}