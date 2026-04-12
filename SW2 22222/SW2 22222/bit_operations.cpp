#include "bit_operations.h"


void swapHalfWord(unsigned int* words) {
    *words = ((*words << 16) | (*words >> 16));
}
void cycleShift(int* number, int N, int left) {
    N = N % 32;
    if (N == 0) return; 
    unsigned int num = *number;

    if (left) {
        num = (num << N) | (num >> (32 - N));
    }
    else {
        num = (num >> N) | (num << (32 - N));
    }
    *number = num;
}