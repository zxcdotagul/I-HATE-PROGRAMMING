#ifndef BOX_H
#define BOX_H

#include <iostream>

struct Box {
    int len;
    int width;
    int height;
    int volume;
    int color;
    int nameBox;

    Box();
    Box(int value);
    Box(int len, int width, int height);

    void calculateVolume();
};

std::ostream& operator<<(std::ostream& os, const Box& box);

void writeToFile(const char* fileName, const struct Box& box);
void readFromFile(const char* fileName, struct Box* box);

#endif // BOX_H
