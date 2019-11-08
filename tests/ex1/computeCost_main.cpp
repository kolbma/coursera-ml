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

    parse_mat(&X, "[1,2; 1,3; 1,4; 1,5]");
    parse_mat(&y, "[7;6;5;4]");
    parse_mat(&theta, "[0.1;0.2]");

    auto J = computeCost(X, y, theta);
    cout << "J = " << J << endl;
    assert(J == 11.945f);

    parse_mat(&X, "[1,2,3; 1,3,4; 1,4,5; 1,5,6]");
    parse_mat(&y, "[7;6;5;4]");
    parse_mat(&theta, "[0.1;0.2;0.3]");

    J = computeCost(X, y, theta);
    cout << "J = " << J << endl;
    assert(J == 7.0175f);

    return 0;
}
