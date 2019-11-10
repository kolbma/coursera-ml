// normalEqn.cpp
#include "normalEqn.hpp"

using namespace std;
using namespace arma;

void normalEqn(shared_ptr<fvec> &theta, const shared_ptr<fmat> &X, const shared_ptr<fvec> &y)
{
    if (!theta)
    {
        theta.reset(new fvec());
    }
    theta->zeros(X->n_cols);

    *theta = pinv(X->t() * (*X)) * X->t() * (*y);
}
