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
}

void PrefixSolver::RandArray(unsigned int size) {
    this->array.reserve(size);
    std::generate(this->array.begin(), this->array.end(), std::rand);
}

void PrefixSolver::Solve(Operators action) {
    switch (action) {
        case Addition:
            std::cout << "[Addition]" << std::endl;

            break;
        case Multiplication:
            std::cout << "[Multiplication]" << std::endl;

            break;
        case Subtraction:
            std::cout << "[Subtraction]" << std::endl;

            break;
        default:
            std::cout << "[1] sorry, unknown operator." << std::endl;
            break;
    }
}