#ifndef RK_1_H
#define RK_1_H

#include <iostream>

struct Box {
    int _len;    
    int _width;    
    int _height;  
    int _color;   
    int _volume;  
    Box();
    Box(int value);
    Box(int len, int width, int height);
};

std::ostream& operator<<(std::ostream& os, const Box& box);

#endif
