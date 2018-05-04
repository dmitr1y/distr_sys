//
// Created by dmitriy on 16.04.18.
//

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <thread>
#include "PrefixSolver.h"

PrefixSolver::PrefixSolver(unsigned int size) {
    this->cpuCount = std::thread::hardware_concurrency();
    this->RandArray(size);
    this->result = this->array;
    std::cout << "rand array: ";
    ShowArray(this->array);
    this->threadsCount = 8;
}

void PrefixSolver::RandArray(unsigned int size) {
    std::cout << "generating rand vector with size " << size << std::endl;
//    this->array.resize(size);
//    std::generate(this->array.begin(), this->array.end(), std::rand);
    this->array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
}

void PrefixSolver::Solve(Operators action) {
    this->Solver(action);
}

void PrefixSolver::Solver(Operators action) {
    this->result.resize(this->array.size());
    this->result[0] = this->array[0];

    for (int i = 1; i < this->array.size(); ++i) {
        switch (action) {
            case Addition:
                this->result[i] = this->result[i - 1] + this->array[i];
                break;
            case Multiplication:
                this->result[i] = this->result[i - 1] * this->array[i];
                break;
            case Subtraction:
                this->result[i] = this->result[i - 1] - this->array[i];
                break;
            default:
                return;
        }

    }
}

void PrefixSolver::ShowArray(std::vector<int> array) {
    for (auto element:array)
        std::cout << element << ", ";
    std::cout << std::endl;
}

void PrefixSolver::ShowResult() {
    std::cout << "result is:  ";
    this->ShowArray(this->result);
}

PrefixSolver::PrefixSolver(unsigned int size, unsigned int threadsCount) {
    this->PrefixSolver(size);
    this->threadsCount = threadsCount;
}
