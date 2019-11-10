// gradientDescent_main.cpp
#include <iostream>
#include <string>
#include "gradientDescent.hpp"
#include "util.hpp"

using namespace std;
using namespace arma;

int main(int argc, char **argv)
{
    if (argc >= 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
    {
        cout << argv[0] << ": usage \"X-matrix\" \"y-vec\" \"theta-vec\" alpha num_iters" << endl
             << "\t example matrix \"[1,2;3,4;5,6]\"" << endl
             << "\t example vector \"[7;8;9]\"" << endl
             << "\t alpha float" << endl
             << "\t num_iters integer" << endl;
        return 0;
    }
    if (argc != 6)
    {
        cerr << argv[0] << ": missing parameters (see --help)" << endl;
        return 1;
    }

    auto J_hist = make_shared<fvec>();
    auto X = make_shared<fmat>();
    auto Xp = X.get();
    auto y = make_shared<fvec>();
    auto yp = y.get();
    auto theta = make_shared<fvec>();
    auto thetap = theta.get();
    float alpha;
    size_t num_iters;

    try
    {
        parse_mat(Xp, argv[1]);
        parse_mat(yp, argv[2]);
        parse_mat(thetap, argv[3]);
        alpha = stof(argv[4]);
        num_iters = stoull(argv[5]);
    }
    catch (const exception &e)
    {
        cerr << argv[0] << ": parameter not parseable (see --help)" << endl
             << e.what() << endl;
        return 1;
    }

    gradientDescent(J_hist, theta, X, y, alpha, num_iters);

    cout << "J = " << endl
         << *J_hist << endl
         << "theta = " << endl
         << *theta << endl;

    return 0;
}
