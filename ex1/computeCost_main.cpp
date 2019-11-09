// computeCost_main.cpp
#include <cstring>
#include <iostream>
#include "computeCost.hpp"
#include "util.hpp"

using namespace std;
using namespace arma;

int main(int argc, char **argv)
{
    if (argc >= 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
    {
        cout << argv[0] << ": usage \"X\" \"y\" \"theta\"" << endl
             << "\t example matrix \"[1,2;3,4;5,6]\"" << endl
             << "\t example vector \"[7;8;9]\"" << endl;
        return 0;
    }
    if (argc != 4)
    {
        cerr << argv[0] << ": missing parameters (see --help)" << endl;
        return 1;
    }

    fmat X;
    fvec y, theta;

    try
    {
        parse_mat(&X, argv[1]);
        parse_mat(&y, argv[2]);
        parse_mat(&theta, argv[3]);
    }
    catch (const exception &e)
    {
        cerr << argv[0] << ": parameter not parseable (see --help)" << endl
             << e.what() << endl;
        return 1;
    }

    cout << "J = " << computeCost(X, y, theta) << endl;

    return 0;
}
