// plotData_main.cpp
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "plotData.hpp"

using namespace std;

int main(int argc, char **argv)
{
    vector<double> x, y;

    if (argc <= 1)
    {
        // sample data
        for (double i = 0.0; i < 20.0; i += 0.5)
        {
            x.push_back(i);
            y.push_back(1.2 * i + i * i);
        }
    }
    else
    {
        // csv data file specified as command argument
        fstream fs(argv[1], fstream::in);
        if (!fs.is_open())
        {
            cerr << argv[0] << ": failed to open file " << argv[1] << endl;
            return 1;
        }
        char linebuf[MAX_LINE_LEN + 1];
        while (fs.getline(linebuf, MAX_LINE_LEN))
        {
            string s(linebuf);
            const auto pos = s.find(',');
            x.push_back(stod(s.substr(0, pos)));
            y.push_back(stod(s.substr(pos + 1)));
        }
        fs.close();
    }

    plotData(x, y);

    return 0;
}
