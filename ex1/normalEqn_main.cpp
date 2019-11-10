// normalEqn_main.cpp
#include "normalEqn.hpp"
#include "util.hpp"

using namespace std;
using namespace arma;

int main(int argc, char **argv)
{
    if (argc >= 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))
    {
        cout << argv[0] << ": usage \"X-matrix\" \"y-vec\"" << endl
             << "\t example matrix \"[1,2;3,4;5,6]\"" << endl
             << "\t example vector \"[7;8;9]\"" << endl;
        return 0;
    }
    if (argc != 3)
    {
        cerr << argv[0] << ": missing parameters (see --help)" << endl;
        return 1;
    }

    auto theta = make_shared<fvec>();
    auto X = make_shared<fmat>();
    auto y = make_shared<fvec>();

    try
    {
        parse_mat(X.get(), argv[1]);
        parse_mat(y.get(), argv[2]);
    }
    catch (const exception &e)
    {
        cerr << argv[0] << ": parameter not parseable (see --help)" << endl
             << e.what() << endl;
        return 1;
    }

    normalEqn(theta, X, y);

    cout << "theta:" << endl
         << *theta << endl;

    return 0;
}
