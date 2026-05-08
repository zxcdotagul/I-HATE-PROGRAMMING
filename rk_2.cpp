#include "rk_2.h"
#include <fstream>
#include <cmath>
#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define GNUPLOT_PATH "gnuplot.exe"
#define popen _popen
#define pclose _pclose
#else
#define GNUPLOT_PATH "gnuplot"
#endif

ProcessPulses::ProcessPulses() : DoubleLinkedList(), globalNormalizationMax(1.0), fileName("") {}

ProcessPulses::ProcessPulses(const char* fileName) : DoubleLinkedList(), globalNormalizationMax(1.0), fileName(fileName) {
    loadFromFile(fileName);
}

ProcessPulses::~ProcessPulses() {}

uint16_t ProcessPulses::readUint16(const uint8_t* data, int offset) {
    return static_cast<uint16_t>(data[offset]) | (static_cast<uint16_t>(data[offset + 1]) << 8);
}

void ProcessPulses::loadFromFile(const char* fileName) {
    std::ifstream file(fileName, std::ios::binary);
    if (!file.is_open()) return;

    file.seekg(0, std::ios::end);
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    if (fileSize < 4) {
        file.close();
        return;
    }

    std::vector<uint8_t> buffer(fileSize);
    file.read(reinterpret_cast<char*>(buffer.data()), fileSize);
    file.close();

    int numPairs = fileSize / 4;
    if (numPairs == 0) return;

    std::vector<double> voltages;
    std::vector<double> currents;

    for (int i = 0; i < numPairs; i++) {
        uint16_t u = readUint16(buffer.data(), i * 4);
        uint16_t iVal = readUint16(buffer.data(), i * 4 + 2);

        voltages.push_back(static_cast<double>(u));
        currents.push_back(static_cast<double>(iVal));
    }

    double threshold = 100.0;
    std::vector<std::vector<std::pair<double, double>>> pulses;
    std::vector<std::pair<double, double>> currentPulse;
    bool inPulse = false;
    double timeStep = 1.0 / 1000.0;

    for (size_t i = 0; i < currents.size(); i++) {
        double time = i * timeStep;

        if (currents[i] > threshold && !inPulse) {
            inPulse = true;
            currentPulse.clear();
        }

        if (inPulse) {
            currentPulse.push_back({ time, currents[i] });
        }

        if (currents[i] <= threshold && inPulse) {
            if (currentPulse.size() > 10) {
                pulses.push_back(currentPulse);
            }
            inPulse = false;
        }
    }

    if (inPulse && currentPulse.size() > 10) {
        pulses.push_back(currentPulse);
    }

    for (auto& pulse : pulses) {
        Data* data = new Data();
        data->pulseData = pulse;
        data->calculateMaxMin();
        push_back(data);
        delete data;
    }

    normalizationCoeff();
}

double ProcessPulses::normalizationCoeff() {
    globalNormalizationMax = 0;
    Node* current = getHead();
    while (current) {
        if (current->data && current->data->maxValue > globalNormalizationMax) {
            globalNormalizationMax = current->data->maxValue;
        }
        current = current->next;
    }
    return globalNormalizationMax;
}

std::vector<std::pair<double, double>> ProcessPulses::getPulse(int numNode, bool normalize) const {
    auto pulse = get_Node(numNode);
    if (normalize && globalNormalizationMax > 0) {
        for (auto& p : pulse) {
            p.second /= globalNormalizationMax;
        }
    }
    return pulse;
}

std::vector<std::pair<double, double>> ProcessPulses::averPulse(int startNode, int countNode) const {
    std::vector<std::pair<double, double>> result;

    if (countNode <= 0 || startNode < 0 || startNode >= getCountNodes()) {
        return result;
    }

    int endNode = std::min(startNode + countNode, getCountNodes());
    int actualCount = endNode - startNode;

    if (actualCount <= 0) return result;

    auto firstPulse = get_Node(startNode);
    if (firstPulse.empty()) return result;

    for (const auto& point : firstPulse) {
        result.push_back({ point.first, 0.0 });
    }

    for (int i = startNode; i < endNode; i++) {
        auto pulse = get_Node(i);
        for (size_t j = 0; j < result.size() && j < pulse.size(); j++) {
            result[j].second += pulse[j].second;
        }
    }

    for (auto& point : result) {
        point.second /= actualCount;
    }

    return result;
}

std::vector<std::pair<double, double>> ProcessPulses::diffPulse(int numNode) const {
    auto pulse = get_Node(numNode);
    std::vector<std::pair<double, double>> result;

    if (pulse.size() < 2) return result;

    for (size_t i = 1; i < pulse.size(); i++) {
        double dt = pulse[i].first - pulse[i - 1].first;
        if (dt > 0) {
            double derivative = (pulse[i].second - pulse[i - 1].second) / dt;
            result.push_back({ pulse[i].first, derivative });
        }
    }

    return result;
}

std::vector<std::pair<double, double>> ProcessPulses::intPulse(int numNode, int start, int end) const {
    auto pulse = get_Node(numNode);
    std::vector<std::pair<double, double>> result;

    if (pulse.empty()) return result;

    int startIdx = std::max(0, start);
    int endIdx = std::min(static_cast<int>(pulse.size()) - 1, end);

    if (startIdx >= endIdx) return result;

    double integral = 0;
    result.push_back({ pulse[startIdx].first, integral });

    for (int i = startIdx + 1; i <= endIdx; i++) {
        double dt = pulse[i].first - pulse[i - 1].first;
        double avg = (pulse[i].second + pulse[i - 1].second) / 2.0;
        integral += avg * dt;
        result.push_back({ pulse[i].first, integral });
    }

    return result;
}

double ProcessPulses::getRiseTime(int numNode) const {
    auto pulse = get_Node(numNode);
    if (pulse.empty()) return 0;

    double minVal = 1e9, maxVal = -1e9;
    for (const auto& p : pulse) {
        if (p.second < minVal) minVal = p.second;
        if (p.second > maxVal) maxVal = p.second;
    }

    double amplitude = maxVal - minVal;
    if (amplitude <= 0) return 0;

    double level10 = minVal + amplitude * 0.1;
    double level90 = minVal + amplitude * 0.9;

    double time10 = -1, time90 = -1;

    for (const auto& p : pulse) {
        if (time10 < 0 && p.second >= level10) time10 = p.first;
        if (time90 < 0 && p.second >= level90) time90 = p.first;
    }

    if (time10 >= 0 && time90 >= 0 && time90 > time10) {
        return time90 - time10;
    }
    return 0;
}

double ProcessPulses::getFallTime(int numNode) const {
    auto pulse = get_Node(numNode);
    if (pulse.empty()) return 0;

    double maxVal = -1e9;
    for (const auto& p : pulse) {
        if (p.second > maxVal) maxVal = p.second;
    }

    double level90 = maxVal * 0.9;
    double level10 = maxVal * 0.1;

    double time90 = -1, time10 = -1;

    for (const auto& p : pulse) {
        if (time90 < 0 && p.second <= level90) time90 = p.first;
        if (time10 < 0 && p.second <= level10) time10 = p.first;
    }

    if (time90 >= 0 && time10 >= 0 && time10 > time90) {
        return time10 - time90;
    }
    return 0;
}

double ProcessPulses::getAmpl(int numNode) const {
    auto pulse = get_Node(numNode);
    if (pulse.empty()) return 0;

    double maxVal = -1e9;
    for (const auto& p : pulse) {
        if (p.second > maxVal) maxVal = p.second;
    }
    return maxVal;
}

int ProcessPulses::getCountPulse() const {
    return getCountNodes();
}

double ProcessPulses::getDurPulse(int numNode, int startPercent, int endPercent) const {
    auto pulse = get_Node(numNode);
    if (pulse.empty()) return 0;

    double maxVal = -1e9;
    for (const auto& p : pulse) {
        if (p.second > maxVal) maxVal = p.second;
    }

    double startLevel = maxVal * startPercent / 100.0;
    double endLevel = maxVal * endPercent / 100.0;

    double startTime = -1, endTime = -1;

    for (const auto& p : pulse) {
        if (startTime < 0 && p.second >= startLevel) startTime = p.first;
        if (endTime < 0 && p.second >= endLevel) endTime = p.first;
    }

    if (startTime >= 0 && endTime >= 0 && endTime > startTime) {
        return endTime - startTime;
    }
    return 0;
}

Gnuplot::Gnuplot() : pipe(nullptr), plotCount(0) {
    pipe = popen(GNUPLOT_PATH, "w");
    if (pipe) {
        fprintf(pipe, "set grid\n");
        fprintf(pipe, "set xlabel 'Time (s)'\n");
        fprintf(pipe, "set ylabel 'Amplitude'\n");
        fflush(pipe);
    }
}

Gnuplot::~Gnuplot() {
    if (pipe) {
        fprintf(pipe, "exit\n");
        pclose(pipe);
    }
}

void Gnuplot::buildPulse(const std::vector<std::pair<double, double>>& pulse, SaveTo paramToSave) {
    if (!pipe || pulse.empty()) return;

    if (paramToSave != SaveTo::show) {
        const char* ext = (paramToSave == SaveTo::png) ? "png" : "jpeg";
        std::string filename = "pulse_" + std::to_string(plotCount++) + "." + ext;
        fprintf(pipe, "set terminal %s\n", ext);
        fprintf(pipe, "set output '%s'\n", filename.c_str());
    }
    else {
        fprintf(pipe, "set terminal qt\n");
        fprintf(pipe, "set output\n");
    }

    fprintf(pipe, "plot '-' with lines title 'Pulse'\n");

    for (const auto& point : pulse) {
        fprintf(pipe, "%f %f\n", point.first, point.second);
    }
    fprintf(pipe, "e\n");
    fflush(pipe);

    if (paramToSave == SaveTo::show) {
        fprintf(pipe, "pause mouse close\n");
        fflush(pipe);
    }
}

void Gnuplot::buildMultiplePulses(const std::vector<std::vector<std::pair<double, double>>>& pulses, SaveTo paramToSave) {
    if (!pipe || pulses.empty()) return;

    if (paramToSave != SaveTo::show) {
        const char* ext = (paramToSave == SaveTo::png) ? "png" : "jpeg";
        std::string filename = "pulses_" + std::to_string(plotCount++) + "." + ext;
        fprintf(pipe, "set terminal %s\n", ext);
        fprintf(pipe, "set output '%s'\n", filename.c_str());
    }
    else {
        fprintf(pipe, "set terminal qt\n");
        fprintf(pipe, "set output\n");
    }

    fprintf(pipe, "plot ");
    for (size_t i = 0; i < pulses.size(); i++) {
        fprintf(pipe, "'-' with lines title 'Pulse %zu'", i);
        if (i < pulses.size() - 1) fprintf(pipe, ", ");
    }
    fprintf(pipe, "\n");

    for (const auto& pulse : pulses) {
        for (const auto& point : pulse) {
            fprintf(pipe, "%f %f\n", point.first, point.second);
        }
        fprintf(pipe, "e\n");
    }
    fflush(pipe);

    if (paramToSave == SaveTo::show) {
        fprintf(pipe, "pause mouse close\n");
        fflush(pipe);
    }
}