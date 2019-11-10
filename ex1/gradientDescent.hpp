// gradientDescent.hpp
#ifndef COURSERA_GRADIENTDESCENT_HPP
#define COURSERA_GRADIENTDESCENT_HPP

#include <memory>
#include <armadillo>

void gradientDescent(std::shared_ptr<arma::fvec> &J_history, std::shared_ptr<arma::fvec> &theta,
                     const std::shared_ptr<arma::fmat> &X, const std::shared_ptr<arma::fvec> &y,
                     const float alpha, const size_t num_iters);

#endif // COURSERA_GRADIENTDESCENT_HPP
