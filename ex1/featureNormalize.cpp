// featureNormalize.cpp
#include "featureNormalize.hpp"

using namespace std;
using namespace arma;

void featureNormalize(shared_ptr<fmat> &X_norm, shared_ptr<frowvec> &mu,
                      shared_ptr<frowvec> &sigma, const fmat &X)
{
    if (!X_norm)
    {
        X_norm.reset(new fmat());
    }
    X_norm->copy_size(X);
    *X_norm = X;
    if (!mu)
    {
        mu.reset(new frowvec());
    }
    mu->zeros(1, X.n_cols);
    if (!sigma)
    {
        sigma.reset(new frowvec());
    }
    sigma->zeros(1, X.n_cols);

    *mu = mean(X);
    X_norm->each_row() -= *mu;
    *sigma = stddev(X);
    X_norm->each_row() /= *sigma;
}
