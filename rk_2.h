#ifndef RK_2_H
#define RK_2_H

#include "double_linked_list.h"
#include <vector>
#include <utility>
#include <string>
#include <cstdint>

class ProcessPulses : public DoubleLinkedList {
private:
    double globalNormalizationMax;
    std::string fileName;

    double normalizationCoeff();
    void loadFromFile(const char* fileName);
    uint16_t readUint16(const uint8_t* data, int offset);

public:
    ProcessPulses();
    ProcessPulses(const char* fileName);
    ~ProcessPulses();

    std::vector<std::pair<double, double>> getPulse(int numNode, bool normalize = false) const;
    std::vector<std::pair<double, double>> averPulse(int startNode, int countNode) const;
    std::vector<std::pair<double, double>> diffPulse(int numNode) const;
    std::vector<std::pair<double, double>> intPulse(int numNode, int start, int end) const;
    double getRiseTime(int numNode) const;
    double getFallTime(int numNode) const;
    double getAmpl(int numNode) const;
    int getCountPulse() const;
    double getDurPulse(int numNode, int startPercent, int endPercent) const;
};

enum class SaveTo {
    show = 0,
    png = 1,
    jpeg = 2
};

class Gnuplot {
private:
    FILE* pipe;
    int plotCount;

public:
    Gnuplot();
    ~Gnuplot();

    void buildPulse(const std::vector<std::pair<double, double>>& pulse, SaveTo paramToSave);
    void buildMultiplePulses(const std::vector<std::vector<std::pair<double, double>>>& pulses, SaveTo paramToSave);
};

#endif
