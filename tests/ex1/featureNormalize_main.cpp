// test featureNormalize
#include <cassert>
#include "../../ex1/featureNormalize.hpp"
#include "../../ex1/util.hpp"

using namespace std;
using namespace arma;

int main()
{
    auto X_norm = make_shared<fmat>();
    auto mu = make_shared<frowvec>();
    auto sigma = make_shared<frowvec>();

    fmat X;
    X << 1 << endr << 2 << endr << 3 << endr;
    featureNormalize(X_norm, mu, sigma, X);

    fmat compm;
    compm << -1.0f << endr << 0.0f << endr << 1.0f << endr;
    assert(all(vectorise(*X_norm == compm)));
    assert((*mu)(0) == 2.0f);
    assert((*sigma)(0) == 1.0f);

    X_norm.reset();
    mu.reset();
    sigma.reset();

    X = {{8.0f, 1.0f, 6.0f}, {3.0f, 5.0f, 7.0f}, {4.0f, 9.0f, 2.0f}}; // magic matrix 3x3
    featureNormalize(X_norm, mu, sigma, X);

    compm = {{1.13389f, -1.00000f, 0.37796f}, {-0.75593f, 0.00000f, 0.75593f}, {-0.37796f, 1.00000f, -1.13389f}};
    assert(compare_mat(*X_norm, compm, 5));
    frowvec compv = {5.0f, 5.0f, 5.0f};
    assert(compare_mat(*mu, compv, 1));
    compv = {2.6458f, 4.0000f, 2.6458f};
    assert(compare_mat(*sigma, compv, 4));

    X_norm.reset();
    mu.reset();
    sigma.reset();

    X = {{-1.0f, -1.0f, -1.0f}, {8.0f, 1.0f, 6.0f}, {3.0f, 5.0f, 7.0f}, {4.0f, 9.0f, 2.0f}};
    featureNormalize(X_norm, mu, sigma, X);

    compm = {{-1.21725f, -1.01472f, -1.21725f}, {1.21725f, -0.56373f, 0.67625f}, {-0.13525f, 0.33824f, 0.94675f}, {0.13525f, 1.24022f, -0.40575f}};
    assert(compare_mat(*X_norm, compm, 5));
    compv = {3.5000f, 3.5000f, 3.5000f};
    assert(compare_mat(*mu, compv, 4));
    compv = {3.6968f, 4.4347f, 3.6968f};
    assert(compare_mat(*sigma, compv, 4));

    return 0;
}
