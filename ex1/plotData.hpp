// plotData.hpp
#ifndef COURSERA_PLOTDATA_HPP
#define COURSERA_PLOTDATA_HPP

#include <vector>

#ifndef CMAKE_TESTING_ENABLED
#define PLPLOT_DEVICE "xcairo"
#define PLPLOT_FNAME ""
#else
#define PLPLOT_DEVICE "svgcairo"
#define PLPLOT_FNAME "plotData.svg"
#endif

#define MAX_LINE_LEN 1024

void plotData(const std::vector<double> &x, const std::vector<double> &y);

#endif // COURSERA_PLOTDATA_HPP
