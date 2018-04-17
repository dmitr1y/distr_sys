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
//    this->RandArray(size);
    this->array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
}

void PrefixSolver::RandArray(unsigned int size) {
    this->array.clear();
    this->array.reserve(size);
    this->array.insert(this->array.begin(), size, 0);
    std::generate(this->array.begin(), this->array.end(), std::rand);
}

void PrefixSolver::Solve(Operators action) {
    int start = 0, end = this->array.size();
    std::vector<int> result(this->array.begin() + start, this->array.begin() + end);
    std::cout << "vector: " << std::endl;
    this->ShowVector(result);

    for (int j = 1; j < result.size(); ++j) {
        switch (action) {
            case Addition:
                std::cout << "[Addition]" << std::endl;
                std::cout << result[j] << " + " << result[j - 1] << std::endl;
                result[j] += result[j - 1];
                break;
            case Multiplication:
                std::cout << "[Multiplication]" << std::endl;

                break;
            case Subtraction:
                std::cout << "[Subtraction]" << std::endl;

                break;
            default:
                std::cout << "[!] sorry, unknown operator." << std::endl;
                break;
        }
    }
    std::cout << "result: " << std::endl;
    this->ShowVector(result);
}

void PrefixSolver::ShowVector(std::vector<int> vector) {
    for (auto val:vector)
        std::cout << val << " ";
    std::cout << std::endl;
}

void PrefixSolver::ShowVector() {
    this->ShowVector(this->array);
}
