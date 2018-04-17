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
    void ShowVector(std::vector<int> vector);

    void ApplyAction(Operators action, unsigned int start, unsigned int stop);

public:
    unsigned int cpuCount;

    PrefixSolver(unsigned int size);

    void RandArray(unsigned int size);

    void Solve(Operators action);

    void ShowVector();
};


#endif //DISTR_SYS_PREFIXSOLVER_H
