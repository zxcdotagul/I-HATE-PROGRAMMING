#include "file_operations.h"

void fillFile(const char* fileName, int min, int max, char delimeter, int cols, int countElements) {
    std::ofstream file(fileName);

    if (!file.is_open()) 
       return;
    

    srand(time(NULL));

    int* ar = new int[countElements];

    for (int i = 0; i < countElements; i++) {
        ar[i] = min + rand() % (max - min + 1);
    }

    for (int i = 0; i < countElements; i++) {
        file << ar[i];

        if ((i + 1) % cols == 0) {
            file << std::endl;
        }
        else if (i != countElements - 1) {
            file << delimeter;
        }
    }

    delete[] ar;
    file.close();

    std::ifstream readFile(fileName);
    

    char ch;
    while (readFile.get(ch)) {
        std::cout << ch;
    }
   
}