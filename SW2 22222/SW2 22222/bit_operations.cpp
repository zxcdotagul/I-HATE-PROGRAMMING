#include "bit_operations.h"


void swapHalfWord(unsigned int* words) {
    *words = ((*words << 16) | (*words >> 16));
}

