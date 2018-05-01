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
    std::vector<int> result;

private:
    void Adder();

    void ShowArray(std::vector<int> array);

public:
    unsigned int cpuCount;

    PrefixSolver(unsigned int size);

    void RandArray(unsigned int size);

    void Solve(Operators action);

    void ShowResult();

};


#endif //DISTR_SYS_PREFIXSOLVER_H
