#ifndef SORTS_H
#define SORTS_H


void bubbleSort(int* ar, int size, bool (*comp)(int, int));
void selectionSort(int* ar, unsigned int size, bool ascending);
void insertionSort(int* ar, int size, bool (*comp)(int, int));
void mergeSort(int* ar, int size, bool (*comp)(int, int));
void quickSort(int* ar, int size, bool (*comp)(int, int));
void sortShell(int* ar, int size, bool (*comp)(int, int));
void countSort(int* ar, int size, bool (*comp)(int, int));


void merge(int* ar, int left, int mid, int right, bool (*comp)(int, int));
void mergeSortRecursive(int* ar, int left, int right, bool (*comp)(int, int));
void quickSortRecursive(int* ar, int left, int right, bool (*comp)(int, int));
int partition(int* ar, int left, int right, bool (*comp)(int, int));


#endif