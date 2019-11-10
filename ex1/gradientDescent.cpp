// gradientDescent.cpp
#include "gradientDescent.hpp"
#include "computeCost.hpp"

using namespace std;
using namespace arma;

void gradientDescent(shared_ptr<fvec> &J_history, shared_ptr<fvec> &theta,
                     const shared_ptr<fmat> &X, const shared_ptr<fvec> &y,
                     const float alpha, const size_t num_iters)
{
    const auto m = y->n_rows;

    if (!J_history)
    {
        J_history.reset(new fvec());
    }
    J_history->zeros(num_iters);

    for (size_t i = 0; i < num_iters; i++)
    {
        auto h = (*X) * (*theta);
        fvec e = h - (*y);
        *theta -= 1.0f / m * alpha * ((*X).t() * e);

        J_history->at(i) = computeCost(*X, *y, *theta);
    }
}
