#ifndef BOX_H
#define BOX_H

struct Box {
    int _len;    // длина
    int _width;  // ширина
    int _height; // высота
    int _color;  // цвет
};

void writeToFile(const char* fileName, const struct Box& box);
void readFromFile(const char* fileName, struct Box& box);

#endif // BOX_H
