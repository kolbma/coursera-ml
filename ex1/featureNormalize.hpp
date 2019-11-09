// featureNormalize.hpp
#ifndef COURSERA_FEATURENORMALIZE_HPP
#define COURSERA_FEATURENORMALIZE_HPP

#include <memory>
#include <armadillo>

void featureNormalize(std::shared_ptr<arma::fmat> &X_norm, std::shared_ptr<arma::frowvec> &mu,
                      std::shared_ptr<arma::frowvec> &sigma, const arma::fmat &X);

#endif // COURSERA_FEATURENORMALIZE_HPP
