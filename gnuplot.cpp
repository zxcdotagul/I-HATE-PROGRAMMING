#include "gnuplot.h"
#include <cstdio>
#include <cmath>

#ifdef _WIN32
#define GNUPLOT_PATH "gnuplot.exe"
#define popen _popen
#define pclose _pclose
#else
#define GNUPLOT_PATH "gnuplot"
#endif

Gnuplot::Gnuplot() : pipe(nullptr), plotCount(0) {
    pipe = popen(GNUPLOT_PATH, "w");
    if (pipe) {
        fprintf(pipe, "set grid\n");
        fflush(pipe);
    }
}

Gnuplot::~Gnuplot() {
    if (pipe) {
        fprintf(pipe, "exit\n");
        pclose(pipe);
    }
}

void Gnuplot::buildPlot(const std::vector<std::pair<double, double>>& data,
    const std::string& title,
    const std::string& xlabel,
    const std::string& ylabel,
    SaveTo saveTo) {
    if (!pipe || data.empty()) return;

    if (saveTo != SaveTo::show) {
        const char* ext = (saveTo == SaveTo::png) ? "png" : "jpeg";
        std::string filename = "plot_" + std::to_string(plotCount++) + "." + ext;
        fprintf(pipe, "set terminal %s size 1024,768\n", ext);
        fprintf(pipe, "set output '%s'\n", filename.c_str());
    }
    else {
        fprintf(pipe, "set terminal qt persist\n");
        fprintf(pipe, "set output\n");
    }

    fprintf(pipe, "set xlabel '%s'\n", xlabel.c_str());
    fprintf(pipe, "set ylabel '%s'\n", ylabel.c_str());
    fprintf(pipe, "set title '%s'\n", title.c_str());
    fprintf(pipe, "plot '-' with lines lw 2 title '%s'\n", title.c_str());

    for (const auto& point : data) {
        fprintf(pipe, "%f %f\n", point.first, point.second);
    }
    fprintf(pipe, "e\n");
    fflush(pipe);

    if (saveTo == SaveTo::show) {
        fprintf(pipe, "pause mouse close\n");
        fflush(pipe);
    }
}

void Gnuplot::buildMultiPlot(const std::vector<std::vector<std::pair<double, double>>>& datas,
    const std::vector<std::string>& titles,
    const std::string& xlabel,
    const std::string& ylabel,
    SaveTo saveTo) {
    if (!pipe || datas.empty()) return;

    if (saveTo != SaveTo::show) {
        const char* ext = (saveTo == SaveTo::png) ? "png" : "jpeg";
        std::string filename = "plot_" + std::to_string(plotCount++) + "." + ext;
        fprintf(pipe, "set terminal %s size 1024,768\n", ext);
        fprintf(pipe, "set output '%s'\n", filename.c_str());
    }
    else {
        fprintf(pipe, "set terminal qt persist\n");
        fprintf(pipe, "set output\n");
    }

    fprintf(pipe, "set xlabel '%s'\n", xlabel.c_str());
    fprintf(pipe, "set ylabel '%s'\n", ylabel.c_str());

    fprintf(pipe, "plot ");
    for (size_t i = 0; i < datas.size(); i++) {
        fprintf(pipe, "'-' with lines lw 2 title '%s'", titles[i].c_str());
        if (i < datas.size() - 1) fprintf(pipe, ", ");
    }
    fprintf(pipe, "\n");

    for (size_t i = 0; i < datas.size(); i++) {
        for (const auto& point : datas[i]) {
            fprintf(pipe, "%f %f\n", point.first, point.second);
        }
        fprintf(pipe, "e\n");
    }
    fflush(pipe);

    if (saveTo == SaveTo::show) {
        fprintf(pipe, "pause mouse close\n");
        fflush(pipe);
    }
}