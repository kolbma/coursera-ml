// plotData.hpp
#ifndef COURSERA_PLOTDATA_HPP
#define COURSERA_PLOTDATA_HPP

#include <vector>

#define PLPLOT_DEVICE "xcairo"
#define MAX_LINE_LEN 1024

void plotData(std::vector<double> x, std::vector<double> y);

#endif // COURSERA_PLOTDATA_HPP
