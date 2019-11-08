// test util
#include <cassert>
#include <armadillo>
#include "../../ex1/util.hpp"

using namespace std;
using namespace arma;

int main()
{
    string s("[1.0,2.0]");
    assert(s.find(",") == 4);
    assert(s.substr(0, 8).find(",", 1) == 4);

    fmat m;

    parse_mat(&m, "[1.0]");
    assert(m.n_rows == 1);
    assert(m.n_cols == 1);

    parse_mat(&m, "[1.0;2.0]");
    assert(m.n_rows == 2);
    assert(m.n_cols == 1);

    parse_mat(&m, "[1.0,2.0]");
    assert(m.n_rows == 1);
    assert(m.n_cols == 2);

    parse_mat(&m, "[1.0,2.0;3.0,4.0;5.0,6.0]");
    assert(m.n_rows == 3);
    assert(m.n_cols == 2);
    assert(m(0, 0) == 1.0);
    assert(m(0, 1) == 2.0);
    assert(m(1, 0) == 3.0);
    assert(m(1, 1) == 4.0);
    assert(m(2, 0) == 5.0);
    assert(m(2, 1) == 6.0);

    parse_mat(&m, "[ 1.0,2.0; 3.0,4.0;5.0, 6.0 ]");
    assert(m.n_rows == 3);
    assert(m.n_cols == 2);

    return 0;
}
