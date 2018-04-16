//
// Created by dmitriy on 16.04.18.
//

#ifndef DISTR_SYS_PREFIXSOLVER_H
#define DISTR_SYS_PREFIXSOLVER_H


#include <vector>

class PrefixSolver {
private:
    std::vector<int> array;
public:
    PrefixSolver(int size);

    void RandArray(int size);

    void Solve();
};


#endif //DISTR_SYS_PREFIXSOLVER_H
