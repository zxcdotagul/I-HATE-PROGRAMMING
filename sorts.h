#ifndef SORTS_H
#define SORTS_H

// Функции сортировок
void bubbleSort(int* ar, int size, bool (*comp)(int, int));
void selectionSort(int* ar, int size, bool (*comp)(int, int));
void insertionSort(int* ar, int size, bool (*comp)(int, int));
void mergeSort(int* ar, int size, bool (*comp)(int, int));
void quickSort(int* ar, int size, bool (*comp)(int, int));
void sortShell(int* ar, int size, bool (*comp)(int, int));
void countSort(int* ar, int size, bool (*comp)(int, int));

// Вспомогательные функции для сортировок
void merge(int* ar, int left, int mid, int right, bool (*comp)(int, int));
void mergeSortRecursive(int* ar, int left, int right, bool (*comp)(int, int));
void quickSortRecursive(int* ar, int left, int right, bool (*comp)(int, int));
int partition(int* ar, int left, int right, bool (*comp)(int, int));

#endif