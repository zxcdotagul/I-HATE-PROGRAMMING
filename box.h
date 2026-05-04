#ifndef BOX_H
#define BOX_H

#include <iostream>

struct Box {
    int _len;
    int _width;
    int _height;
    int _volume;
    int _color;
    int _nameBox;

    Box();
    Box(int value);
    Box(int len, int width, int height);

    void calculateVolume();
};



void writeToFile(const char* fileName, const struct Box& box);
void readFromFile(const char* fileName, struct Box* box);
void readFromFile(const char* fileName, Box& box);  

#endif