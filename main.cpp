

#include "PrefixSolver/PrefixSolver.h"

int main() {
    PrefixSolver prefixSolver(5);
    prefixSolver.ShowVector();
    prefixSolver.Solve(Addition);
//    prefixSolver.ShowVector();

    return 0;
}