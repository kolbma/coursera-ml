// test plotData
#include <cstdio>
#include "../../ex1/plotData.hpp"

using namespace std;

int main()
{
    FILE *f = fopen(PLPLOT_FNAME, "r");
    if (f)
    {
        fclose(f);
        remove(PLPLOT_FNAME);
    }

    vector<double> x, y;

    // sample data
    for (double i = 0.0; i < 20.0; i += 0.5)
    {
        x.push_back(i);
        y.push_back(1.2 * i + i * i);
    }

    plotData(x, y);

    f = fopen(PLPLOT_FNAME, "r");
    if (!f)
    {
        return -1;
    }

    fclose(f);
    remove(PLPLOT_FNAME);

    return 0;
}
