// featureNormalize_main.cpp
#include <iostream>
#include "featureNormalize.hpp"
#include "util.hpp"

using namespace std;
using namespace arma;

int main(int argc, char **argv)
{
    if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
    {
        cout << argv[0] << ": usage \"X\"" << endl
             << "\t example matrix \"[1,2;3,4;5,6]\"" << endl
             << "\t example vector \"[7;8;9]\"" << endl;
        return 0;
    }
    else if (argc != 2)
    {
        cerr << argv[0] << ": missing parameter (see --help)" << endl;
        return 1;
    }

    fmat X;
    try
    {
        parse_mat(&X, argv[1]);
    }
    catch (const exception &e)
    {
        cerr << argv[0] << ": parameter not parseable (see --help)" << endl
             << e.what() << endl;
        return 1;
    }

    auto X_norm = make_shared<fmat>();
    auto mu = make_shared<frowvec>();
    auto sigma = make_shared<frowvec>();

    featureNormalize(X_norm, mu, sigma, X);

    cout << "X_norm = " << endl
         << *X_norm << endl
         << "mu = " << endl
         << *mu << endl
         << "sigma = " << endl
         << *sigma << endl;

    return 0;
}
