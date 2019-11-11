// test predictHousePrice_main.cpp
#include <cassert>
#include "../../ex1_mlpack/predictHousePrice.hpp"
#include "../../ex1/util.hpp"

int main()
{
    const auto prediction = predictHousePrice(1650, 3);
    assert(is_almost_equal(prediction, 293081.464, 3));
    return 0;
}
