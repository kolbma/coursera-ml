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
    *theta = {0, 0};
    auto X = make_shared<fmat>();
    *X = {{1, 5}, {1, 2}, {1, 4}, {1, 5}};
    auto y = make_shared<fvec>();
    *y = {1, 6, 4, 2};

    gradientDescent(J_hist, theta, X, y, 0.01f, 1000);

    assert(is_almost_equal(theta->at(0), 5.2148f, 4));
    assert(is_almost_equal(theta->at(1), -0.5733f, 4));

    assert(is_almost_equal(J_hist->at(999), 0.8543f, 4));
    assert(is_almost_equal(J_hist->at(0), 5.9794f, 4));

    *theta = {0.5, 0.5};
    *X = {{1, 5}, {1, 2}};
    *y = {1, 6};

    gradientDescent(J_hist, theta, X, y, 0.1f, 10);

    assert(is_almost_equal(theta->at(0), 1.70986f, 5));
    assert(is_almost_equal(theta->at(1), 0.19229f, 5));

    assert(is_almost_equal(J_hist->at(9), 4.5117f, 4));
    assert(is_almost_equal(J_hist->at(2), 5.5475f, 4));
    assert(is_almost_equal(J_hist->at(1), 5.7139f, 4));
    assert(is_almost_equal(J_hist->at(0), 5.8853f, 4));

    return 0;
}
