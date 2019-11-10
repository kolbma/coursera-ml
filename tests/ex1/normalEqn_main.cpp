// test normalEqn
#include <cassert>
#include "../../ex1/normalEqn.hpp"
#include "../../ex1/util.hpp"

using namespace std;
using namespace arma;

int main()
{
    auto theta = make_shared<fvec>();
    auto X = make_shared<fmat>();
    auto y = make_shared<fvec>();

    *X = {{2, 1, 3}, {7, 1, 9}, {1, 8, 1}, {3, 7, 4}};
    *y = {2, 5, 5, 6};

    normalEqn(theta, X, y);

    assert(is_almost_equal(theta->at(0), 0.0083857f, 7));
    assert(is_almost_equal(theta->at(1), 0.5681342f, 7));
    assert(is_almost_equal(theta->at(2), 0.4863732f, 7));

    return 0;
}
