

#include "PrefixSolver/PrefixSolver.h"

int main() {
    PrefixSolver prefixSolver(5);
    prefixSolver.ShowVector();
    prefixSolver.Solve(Subtraction);
//    prefixSolver.ShowVector();

    return 0;
}