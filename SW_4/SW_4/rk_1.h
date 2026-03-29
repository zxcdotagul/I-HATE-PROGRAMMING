#ifndef RK_1_H
#define RK_1_H

#include <iostream>

struct Box {
    int _len;     // длина
    int _width;   // ширина
    int _height;  // высота
    int _color;   // цвет
    int _volume;  // объём

    // Конструктор по умолчанию (устанавливает высоту, длину, ширину равную 10)
    Box();

    // Конструктор с одним параметром (инициализирует все поля этим значением)
    Box(int value);

    // Конструктор с тремя параметрами (len, width, height)
    Box(int len, int width, int height);
};

// Переопределение оператора вывода
std::ostream& operator<<(std::ostream& os, const Box& box);

#endif // RK_1_H
