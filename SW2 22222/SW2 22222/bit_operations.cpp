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
int getMaxBit(const int* array, int N) {
    int maxIndex = -1;
    int maxBits = -1;

    for (int i = 0; i < N; i++) {
        if (array[i] < 0) {
            continue;
        }
        unsigned int num = array[i];
        int bitCount = 0;

        while (num != 0) {
            bitCount += (num & 1);
            num >>= 1;
        }

        if (bitCount > maxBits) {
            maxBits = bitCount;
            maxIndex = i;
        }
    }

    return maxIndex;
}