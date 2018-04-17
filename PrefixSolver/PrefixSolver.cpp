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
    unsigned int cpuCount = std::thread::hardware_concurrency();
    std::vector<std::thread> thread_pool(cpuCount);
    int parts = (int) this->array.size() / cpuCount;
    int divParts = (int) this->array.size() % cpuCount;
    std::cout << "parts: " << parts << " div: " << divParts << std::endl;

    for (int i = 0, start = 0, end = 0; i < cpuCount && i < this->array.size(); ++i) {
        end = start + parts;
        if (divParts > 0) {
            end += 1;
            divParts--;
        }
//            std::cout<<"out ["<<i<<"]"<<std::endl;
//            std::cout << "start: " << start << " end: " << end <<  std::endl;
//            std::cout << "div: " << divParts << " parts: " << parts <<  std::endl;
        std::vector<int> keys;
        for (int j = start; j < end; ++j) {
            keys.push_back(this->array[j]);
        }
//            this->PrintArray(keys);
//            std::cout<<"vector size: "<<keys.size()<<std::endl;
        start = end;

        thread_pool.emplace_back(&PrefixSolver::ApplyAction, this, keys);
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

void PrefixSolver::ApplyAction(Operators action, unsigned int start, unsigned int stop) {
    for (int j = 1; j < vector.size(); ++j) {
        switch (action) {
            case Addition:
                std::cout << "[Addition]" << std::endl;
                std::cout << vector[j] << " + " << vector[j - 1] << std::endl;
                vector[j] += vector[j - 1];
                break;
            case Multiplication:
                std::cout << "[Multiplication]" << std::endl;
                vector[j] *= vector[j - 1];
                break;
            case Subtraction:
                std::cout << "[Subtraction]" << std::endl;
                vector[j] -= vector[j - 1];
                break;
            default:
                std::cout << "[!] sorry, unknown operator." << std::endl;
                break;
        }
    }
}
