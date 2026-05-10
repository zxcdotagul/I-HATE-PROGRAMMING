#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <vector>
#include <utility>
#include <string>

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

    void buildPlot(const std::vector<std::pair<double, double>>& data,
        const std::string& title,
        const std::string& xlabel,
        const std::string& ylabel,
        SaveTo saveTo);

    void buildMultiPlot(const std::vector<std::vector<std::pair<double, double>>>& datas,
        const std::vector<std::string>& titles,
        const std::string& xlabel,
        const std::string& ylabel,
        SaveTo saveTo);
};

#endif
