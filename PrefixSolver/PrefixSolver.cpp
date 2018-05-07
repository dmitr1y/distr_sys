//
// Created by dmitriy on 16.04.18.
//

#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <thread>
#include "PrefixSolver.h"

PrefixSolver::PrefixSolver() {
    this->threadsCount = 8;
    this->cpuCount = std::thread::hardware_concurrency();
    this->RandArray(8);
    this->result = this->array;
    std::cout << "rand array: ";
    ShowArray(this->array);
}

void PrefixSolver::RandArray(unsigned int size) {
    std::cout << "generating rand vector with size " << size << std::endl;
//    todo in release
    this->array.resize(size);
    std::generate(this->array.begin(), this->array.end(), std::rand);
//    this->array = {1, 2, 3, 4, 5, 6, 7, 8, 9};
}

void PrefixSolver::Solve(Operators action) {
    this->Solver(action);
}

void PrefixSolver::Solver(Operators action) {
    if (this->array.empty())
        return; // if the array is empty then we're can't solve anything

    this->result.resize(this->array.size());
    this->result[0] = this->array[0]; //first number doesn't changing

    unsigned int divParts = result.size() / threadsCount, modParts = result.size() % threadsCount;
//    std::vector<unsigned int> partsSizePerThread;
    std::vector<std::thread> threadsPool;
    std::cout << "array size:  [" << result.size() << "] " << " threads count [" << threadsCount << "]: " << std::endl;

    unsigned int partsCount = threadsCount;
    if (divParts < 2) {
        if (modParts < 2) {
//            масив всего из двух элементов
            partsCount = 1;
        } else {
            unsigned int tmpDiv = result.size() / 2; //найдем количество пар, чтобы был смысл параллелить
            unsigned int tmpMod = result.size() % 2;
            divParts = partsCount = tmpDiv;
            modParts = tmpMod;
        }
    }

    //если количество пар из элементов массива меньше или равно количеству потоков, то так и оставляем
    threadsPool.resize(partsCount);


    unsigned int startPos = 1;
//    std::cout << "divParts [" << divParts << "] " << " modParts [" << modParts << "]: " << std::endl;


    for (int j = 0; j < threadsPool.size(); ++j) {
        unsigned int parts = divParts;
        if (modParts > 0) {
            parts++;
            modParts--;
        }
//        std::cout << "parts[" << j << "] " << parts << std::endl;
//        std::cout << "start pos [" << startPos << "] " << " end pos [" << startPos + parts << "]: " << std::endl
//                  << std::endl;

        threadsPool.emplace_back(&PrefixSolver::ApplyActionToRange, this, action, startPos, startPos + parts);
        startPos += parts + 1; //
    }
    for (auto &threads:threadsPool)
        threads.join();
//todo добавить еще 2 операции "суммирования" результатов
    threadsPool.clear();

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
    this->cpuCount = std::thread::hardware_concurrency();
    this->RandArray(size);
    this->result = this->array;
    std::cout << "rand array: ";
    ShowArray(this->array);
    std::cout << std::endl;
    this->threadsCount = threadsCount;
}

void PrefixSolver::ApplyActionToRange(Operators action, unsigned int from, unsigned int to) {
    for (int i = from; i < to; ++i) {
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
