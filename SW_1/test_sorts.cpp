
#include "test_sorts.h"
#include "sorts.h"

bool checkSort(const int* ar, int size) {
    for (int i = 0; i < size - 1; i++) {
        if (ar[i] > ar[i + 1]) {
            return false;
        }
    }
    return true;
}

void test_selectionSort() {
    int ar[4] = { 5,4,3,2 };
    selectionSort(ar, 4);
    if (checkSort(ar, 4) == true) {
        std::cout << "TEST PASSED" << std::endl;
    }
    else {
        std::cout << "TEST FAIL" << std::endl;
    }
}


void test_isSorted() {
    
    int ar1[] = { 1, 2, 3, 4, 5 };
    int res1 = isSorted(ar1, 5);
    std::cout << "Массив [1,2,3,4,5]: " << res1;
    if (res1 == 1) std::cout << " ✓" << std::endl;
    else std::cout << " loh" << std::endl;

    
    int ar2[] = { 5, 4, 3, 2, 1 };
    int res2 = isSorted(ar2, 5);
    std::cout << "Массив [5,4,3,2,1]: " << res2 ;
    if (res2 == -1) std::cout << " ✓" << std::endl;
    else std::cout << " loh" << std::endl;

   
    int ar3[] = { 1, 3, 2, 4, 5 };
    int res3 = isSorted(ar3, 5);
    std::cout << "Массив [1,3,2,4,5]: " << res3 ;
    if (res3 == 0) std::cout << " ✓" << std::endl;
    else std::cout << " loh" << std::endl;

    
    int res4 = isSorted(nullptr, 0);
    std::cout << "Пустой массив: " << res4 ;
    if (res4 == 1) std::cout << " ✓" << std::endl;
    else std::cout << " loh" << std::endl;

   
    int ar5[] = { 42 };
    int res5 = isSorted(ar5, 1);
    std::cout << "Массив [42]: " << res5 ;
    if (res5 == 1) std::cout << " ✓" << std::endl;
    else std::cout << " loh" << std::endl;
}