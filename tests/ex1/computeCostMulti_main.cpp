// test computeCost
#include <cassert>
#include <armadillo>
#include "../../ex1/computeCost.hpp"
#include "../../ex1/util.hpp"

using namespace std;
using namespace arma;

int main()
{
    fmat X;
    fvec y, theta;

    parse_mat(&X, "[ 2, 1, 3; 7, 1, 9; 1, 8, 1; 3, 7, 4 ]");
    parse_mat(&y, "[2 ; 5 ; 5 ; 6]");
    parse_mat(&theta, "[0.4 ; 0.6 ; 0.8]");

    auto J = computeCost(X, y, theta);
    cout << "J = " << J << endl;
    assert(J >= 5.2950f && J < 5.29501f);

    return 0;
}
