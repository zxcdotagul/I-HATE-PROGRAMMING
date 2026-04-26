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

    if (left) {
        
        unsigned int carry = 0;
        for (int i = 0; i < size; i++) {
            unsigned int val = (unsigned int)array[i];
            unsigned int next = (val << N) | carry;
            carry = val >> (32 - N);
            array[i] = (int)next;
        }
       
        if (carry) {
            array[0] = (int)((unsigned int)array[0] | carry);
        }
    }
    else {
       
        unsigned int carry = 0;
        for (int i = size - 1; i >= 0; i--) {
            unsigned int val = (unsigned int)array[i];
            unsigned int next = (val >> N) | carry;
            carry = val << (32 - N);
            array[i] = (int)next;
        }
       
        if (carry) {
            array[size - 1] = (int)((unsigned int)array[size - 1] | carry);
        }
    }
}

void setBit(int* number, int numBit) {
    *number |= (1 << numBit);
}

void clearBit(int* number, int numBit) {
    *number &= ~(1 << numBit);
}
bool isPalindromNumber(const int number) {
    unsigned int num = static_cast<unsigned int>(number);

    for (int i = 0; i < 16; i++) {
        int leftBit = (num >> (31 - i)) & 1;
        int rightBit = (num >> i) & 1;

        if (leftBit != rightBit) {
            return false;
        }
    }

    return true;
}