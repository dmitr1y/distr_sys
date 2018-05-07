

#include "PrefixSolver/PrefixSolver.h"

int main() {
    PrefixSolver prefixSolver(21, 4);
    prefixSolver.Solve(Addition);
//    prefixSolver.Solve(Subtraction);
//    prefixSolver.Solve(Multiplication);
//    prefixSolver.ShowResult();
    return 0;
}