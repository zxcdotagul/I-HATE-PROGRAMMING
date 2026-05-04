#ifndef HW1_H
#define HW1_H

#include <string>


enum class meas {
    milli = 1,
    micro = 2,
    nano = 3,
    pico = 4
};


double getTime(meas unit);
void writeStringToFile(const std::string& fileName, const std::string& data);
std::string convertDoubleToString(double number);
std::string convertIntToString(int number);
void randomFillArr(int* arr, int size, int min = -100, int max = 100);

#endif
