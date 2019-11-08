// computeCost.cpp
#include "computeCost.hpp"

using namespace arma;

float computeCost(const fmat &X, const fvec &y, const fvec &theta)
{
    auto m = y.size();

    auto h = X * theta;
    fvec e = h - y;
    fvec e_sqr = e.for_each([](fmat::elem_type &val) { val = pow(val, 2); });

    return 1.0 / (2 * m) * sum(e_sqr);
}
