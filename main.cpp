

#include "PrefixSolver/PrefixSolver.h"

int main() {
    PrefixSolver prefixSolver(5);
    prefixSolver.Solve(Addition);
    prefixSolver.ShowResult();
    return 0;
}