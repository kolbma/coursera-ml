// predictHousePrice.cpp
#include <mlpack/core/data/load_csv.hpp>
#include <mlpack/methods/linear_regression/linear_regression.hpp>
#include "predictHousePrice.hpp"

using namespace std;
using namespace arma;
using namespace mlpack::data;
using namespace mlpack::regression;

double predictHousePrice(const unsigned int area, const uint8_t rooms)
{
    // mlpack uses a faster representation with rows per feature and samples in columns
    // colvec for fast in-place initialisation
    const colvec points = {static_cast<double>(area), static_cast<double>(rooms)};

    mat matrix;
    Load(DATAFILE, matrix); // does automatic transpose of data r,c => c,r

    const mat data = matrix.rows(0, 1);
    const rowvec response = matrix.row(2);

    LinearRegression lr(data, response);

    rowvec prediction;
    lr.Predict(points, prediction);

    return prediction(0);
}
