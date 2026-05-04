#include "sorts.h"
#include <algorithm>
#include <cstring>


bool ascending(int a, int b) {
    return a < b;
}


void bubbleSort(int* ar, int size, bool (*comp)(int, int)) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (!comp(ar[j], ar[j + 1])) {
                std::swap(ar[j], ar[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}


void selectionSort(int* ar, unsigned int size, bool ascending) {
    for (unsigned int i = 0; i < size - 1; i++) {
        int extremeIdx = i;
        for (unsigned int j = i + 1; j < size; j++) {
            if (ascending ? (ar[j] < ar[extremeIdx]) : (ar[j] > ar[extremeIdx])) {
                extremeIdx = j;
            }
        }
        if (extremeIdx != i) {
            std::swap(ar[i], ar[extremeIdx]);
        }
    }
}


void insertionSort(int* ar, int size, bool (*comp)(int, int)) {
    for (int i = 1; i < size; i++) {
        int key = ar[i];
        int j = i - 1;
        while (j >= 0 && !comp(ar[j], key)) {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = key;
    }
}


void merge(int* ar, int left, int mid, int right, bool (*comp)(int, int)) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    int* leftArr = new int[leftSize];
    int* rightArr = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
        leftArr[i] = ar[left + i];
    for (int i = 0; i < rightSize; i++)
        rightArr[i] = ar[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (comp(leftArr[i], rightArr[j])) {
            ar[k++] = leftArr[i++];
        }
        else {
            ar[k++] = rightArr[j++];
        }
    }

    while (i < leftSize) ar[k++] = leftArr[i++];
    while (j < rightSize) ar[k++] = rightArr[j++];

    delete[] leftArr;
    delete[] rightArr;
}


void mergeSortRecursive(int* ar, int left, int right, bool (*comp)(int, int)) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRecursive(ar, left, mid, comp);
        mergeSortRecursive(ar, mid + 1, right, comp);
        merge(ar, left, mid, right, comp);
    }
}


void mergeSort(int* ar, int size, bool (*comp)(int, int)) {
    mergeSortRecursive(ar, 0, size - 1, comp);
}


int partition(int* ar, int left, int right, bool (*comp)(int, int)) {
    int pivot = ar[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (comp(ar[j], pivot)) {
            i++;
            std::swap(ar[i], ar[j]);
        }
    }
    std::swap(ar[i + 1], ar[right]);
    return i + 1;
}


void quickSortRecursive(int* ar, int left, int right, bool (*comp)(int, int)) {
    if (left < right) {
        int pi = partition(ar, left, right, comp);
        quickSortRecursive(ar, left, pi - 1, comp);
        quickSortRecursive(ar, pi + 1, right, comp);
    }
}


void quickSort(int* ar, int size, bool (*comp)(int, int)) {
    quickSortRecursive(ar, 0, size - 1, comp);
}


void sortShell(int* ar, int size, bool (*comp)(int, int)) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = ar[i];
            int j;
            for (j = i; j >= gap && !comp(ar[j - gap], temp); j -= gap) {
                ar[j] = ar[j - gap];
            }
            ar[j] = temp;
        }
    }
}


void countSort(int* ar, int size, bool (*comp)(int, int)) {
    if (size <= 1) return;

    int minVal = ar[0], maxVal = ar[0];
    for (int i = 1; i < size; i++) {
        if (ar[i] < minVal) minVal = ar[i];
        if (ar[i] > maxVal) maxVal = ar[i];
    }

    int range = maxVal - minVal + 1;
    int* count = new int[range]();
    int* output = new int[size];

    for (int i = 0; i < size; i++) {
        count[ar[i] - minVal]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[ar[i] - minVal] - 1] = ar[i];
        count[ar[i] - minVal]--;
    }

    for (int i = 0; i < size; i++) {
        ar[i] = output[i];
    }

    delete[] count;
    delete[] output;

    if (!comp(1, 2)) {
        for (int i = 0; i < size / 2; i++) {
            std::swap(ar[i], ar[size - 1 - i]);
        }
    }
}