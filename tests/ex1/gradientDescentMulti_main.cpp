// test gradientDescent
#include <cassert>
#include "../../ex1/gradientDescent.hpp"
#include "../../ex1/util.hpp"

using namespace std;
using namespace arma;

int main()
{
    auto J_hist = make_shared<fvec>();
    auto theta = make_shared<fvec>();
    theta->zeros(3);
    auto X = make_shared<fmat>();
    *X = {{2, 1, 3}, {7, 1, 9}, {1, 8, 1}, {3, 7, 4}};
    auto y = make_shared<fvec>();
    *y = {2, 5, 5, 6};

    gradientDescent(J_hist, theta, X, y, 0.01f, 100);

    assert(is_almost_equal(theta->at(0), 0.23680f, 5));
    assert(is_almost_equal(theta->at(1), 0.56524f, 5));
    assert(is_almost_equal(theta->at(2), 0.31248f, 5));

    assert(is_almost_equal(J_hist->at(99), 0.0017196f, 7));
    assert(is_almost_equal(J_hist->at(0), 2.8299f, 4));

    return 0;
}
