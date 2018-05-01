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
    std::cout << "rand array: ";
    ShowArray(this->array);
}

void PrefixSolver::RandArray(unsigned int size) {
    std::cout << "generating rand vector with size " << size << std::endl;
//    this->array.resize(size);
//    std::generate(this->array.begin(), this->array.end(), std::rand);
    this->array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
}

void PrefixSolver::Solve(Operators action) {
    switch (action) {
        case Addition:
            std::cout << "[Addition]" << std::endl;
            this->Adder();
            break;
        case Multiplication:
            std::cout << "[Multiplication]" << std::endl;

            break;
        case Subtraction:
            std::cout << "[Subtraction]" << std::endl;

            break;
        default:
            std::cout << "sorry, unknown operator." << std::endl;
            break;
    }
}

void PrefixSolver::Adder() {
    this->result.resize(this->array.size());
    this->result[0] = this->array[0];
    for (int i = 1; i < this->array.size(); ++i) {
        this->result[i] = this->result[i - 1] + this->array[i];
    }
}

void PrefixSolver::ShowArray(std::vector<int> array) {
    for (auto element:array)
        std::cout << element << ", ";
    std::cout << std::endl;
}

void PrefixSolver::ShowResult() {
    std::cout << "result is: ";
    this->ShowArray(this->result);
}
