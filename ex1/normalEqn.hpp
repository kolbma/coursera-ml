// normalEqn.hpp
#ifndef COURSERA_NORMALEQN_HPP
#define COURSERA_NORMALEQN_HPP

#include <memory>
#include <armadillo>

void normalEqn(std::shared_ptr<arma::fvec> &theta,
               const std::shared_ptr<arma::fmat> &X, const std::shared_ptr<arma::fvec> &y);

#endif // COURSERA_NORMALEQN_HPP
