// test warmUpExercise
#include "../../ex1/warmUpExercise.hpp"

using namespace std;
using namespace arma;

int main() {
    fmat A = warmUpExercise();
    if (A.n_elem != 25 || A.n_cols != 5 || A.n_rows != 5) {
        return -1;
    }
    if (lround(accu(A)) != 5) {
        return -1;
    }
    return 0;
}
