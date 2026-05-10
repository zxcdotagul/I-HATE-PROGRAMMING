#include "parse_fonts.h"
#include "fonts.h"
#include <iostream>

void parse_font(char symbol, char fill, char background) {
    int ascii = static_cast<int>(symbol);

   
    if (ascii < FONT_VERDANA_8_START_CHAR || ascii > FONT_VERDANA_8_START_CHAR + FONT_VERDANA_8_LENGTH - 1) {
        return;
    }

   
    int charIndex = (ascii - FONT_VERDANA_8_START_CHAR) * FONT_VERDANA_8_CHAR_HEIGHT * 2;

   
    for (int row = 0; row < FONT_VERDANA_8_CHAR_HEIGHT; row++) {
       
        unsigned char lowByte = verdana_8_font[charIndex + row * 2];
        unsigned char highByte = verdana_8_font[charIndex + row * 2 + 1];

        unsigned short bits = static_cast<unsigned short>(lowByte) |
            (static_cast<unsigned short>(highByte) << 8);

        for (int col = 0; col < FONT_VERDANA_8_CHAR_WIDTH; col++) {
            bool isSet = (bits >> (15 - col)) & 1;
            std::cout << (isSet ? fill : background);
        }
        std::cout << std::endl;
    }
}