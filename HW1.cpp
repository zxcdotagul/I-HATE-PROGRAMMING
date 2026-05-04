#include "HW1.h"
#include <chrono>
#include <random>
#include <sstream>
#include <iomanip>
#include <fstream>


double getTime(meas unit) {
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = now.time_since_epoch();

    switch (unit) {
    case meas::milli:
        return std::chrono::duration<double, std::milli>(duration).count();
    case meas::micro:
        return std::chrono::duration<double, std::micro>(duration).count();
    case meas::nano:
        return std::chrono::duration<double, std::nano>(duration).count();
    case meas::pico:
        return std::chrono::duration<double, std::pico>(duration).count();
    default:
        return std::chrono::duration<double, std::milli>(duration).count();
    }
}


void writeStringToFile(const std::string& fileName, const std::string& data) {
    std::ofstream file(fileName, std::ios::app);
    if (file.is_open()) {
        file << data;
        file.close();
    }
}


std::string convertDoubleToString(double number) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << number;
    return oss.str();
}


std::string convertIntToString(int number) {
    return std::to_string(number);
}


void randomFillArr(int* arr, int size, int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);

    for (int i = 0; i < size; i++) {
        arr[i] = dist(gen);
    }
}