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

unsigned char getCount1Bit(int number) {
    unsigned int num = number;
    unsigned char count = 0;

    while (num != 0) {
        count += (num & 1);
        num >>= 1;
    }

    return count;
}

void cycleShiftArray(int* array, int size, int N, bool left) {
    if (size == 0 || N == 0) return;

    N = N % 32;

    unsigned int* artem = new unsigned int[size];
    for (int i = 0; i < size; i++) {
        artem[i] = *(unsigned int*)(&array[i]);
    }

    if (left) {
        unsigned int  omagad= artem[0] >> (32 - N);

        for (int i = 0; i < size - 1; i++) {
            artem[i] = (artem[i] << N) | (artem[i + 1] >> (32 - N));
        }

        artem[size - 1] = (artem[size - 1] << N) | omagad;

    }
    else {
        unsigned int carry = artem[size - 1] << (32 - N);

        for (int i = size - 1; i > 0; i--) {
            artem[i] = (artem[i] >> N) | (artem[i - 1] << (32 - N));
        }

        artem[0] = (artem[0] >> N) | carry;
    }

    for (int i = 0; i < size; i++) {
        array[i] = *(int*)(&artem[i]);
    }

    delete[] artem;
}



void setBit(int* number, int numBit) {
    *number |= (1 << numBit);
}

void clearBit(int* number, int numBit) {
    *number &= ~(1 << numBit);
}

