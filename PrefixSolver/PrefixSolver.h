//
// Created by dmitriy on 16.04.18.
//

#ifndef DISTR_SYS_PREFIXSOLVER_H
#define DISTR_SYS_PREFIXSOLVER_H


#include <vector>

enum Operators {
    Addition = 0,
    Multiplication = 1,
    Subtraction = 2
};

class PrefixSolver {
private:
    std::vector<int> array;

private:


public:
    unsigned int cpuCount;

    PrefixSolver(unsigned int size);

    void RandArray(unsigned int size);

    void Solve(Operators action);
};


#endif //DISTR_SYS_PREFIXSOLVER_H
