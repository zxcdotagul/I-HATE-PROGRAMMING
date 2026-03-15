#include "sorts.h"
#include <algorithm>

int getMax(const int* ar, int size) {
    int ind_max = 0;
    for (int i = 1; i < size; i++) {
        if (ar[ind_max] < ar[i]) {
            ind_max = i;
        }
    }
    return ind_max;
}

void selectionSort(int* ar, int size) {
    for (int i = 0; i < size; i++) {
        int indMax = getMax(ar, size - i);
        std::swap(ar[size - i - 1], ar[indMax]);
    }
}

void selSt(int* ar, int size, bool ascending) {
    for (int i = 0; i < size; i++) {
        int indMax = getMax(&ar[ascending == true ? 0 : 1], size - i);
        std::swap(ar[ascending == true ? indMax : indMax + 1], ar[ascending == true ? size - i - 1 : i]);
    }
}

// Реализация новой функции
int isSorted(const int* array, unsigned int size) {
    if (size <= 1) return 1;

    bool ascending = true;
    bool descending = true;

    for (unsigned int i = 1; i < size; i++) {
        if (array[i] > array[i - 1]) {
            descending = false;
        }
        else if (array[i] < array[i - 1]) {
            ascending = false;
        }
    }

    if (ascending) return 1;
    if (descending) return -1;
    return 0;
}


