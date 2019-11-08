// plotData.cpp
#include <algorithm>
#include <plstream.h>
#include "plotData.hpp"

using namespace std;

void plotData(vector<double> x, vector<double> y)
{
    auto minmaxX = minmax_element(x.begin(), x.end());
    auto minmaxY = minmax_element(y.begin(), y.end());
    plstream plot;
    plot.sdev(PLPLOT_DEVICE);
    plot.spal0("cmap0_black_on_white.pal");
    plot.init();
    plot.env(*minmaxX.first, *minmaxX.second, *minmaxY.first, *minmaxY.second, 0, 0);
    plot.lab("population", "profit", "plotData");
    plot.col1(1.0);
    plot.string(x.size(), x.data(), y.data(), "x");
}
