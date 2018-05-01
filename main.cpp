

#include "PrefixSolver/PrefixSolver.h"

int main() {
    PrefixSolver prefixSolver(5);
    prefixSolver.Solve(Addition);
//    prefixSolver.Solve(Subtraction);
//    prefixSolver.Solve(Multiplication);
    prefixSolver.ShowResult();
    return 0;
}