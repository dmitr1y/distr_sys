//
// Created by dmitriy on 06.05.18.
//

#include <random>
#include "Exp.h"

Exp::Exp(unsigned int maxNumberSize, unsigned int threadsCount) {
    this->threadsCount = threadsCount;
    this->maxNumberSize = maxNumberSize;
    this->threadPool.reserve(threadsCount);
}

void Exp::testMSQueue() {
    MSQueue<int> queue;


    for (unsigned int i = 0; i < threadsCount; ++i) {
        threadPool.emplace_back(&Exp::testFunctionMS, this, std::ref(queue));
    }

    for (auto &item:threadPool)
        item.join();
}

void Exp::testMutex() {
    MutexQueue<int> queue;

    for (unsigned int i = 0; i < threadsCount; ++i) {
        threadPool.emplace_back(&Exp::testFunctionMutex, this, std::ref(queue));
    }

    for (auto &item:threadPool)
        item.join();
}

void Exp::testFunctionMS(MSQueue<int> &queue) {
    int temp;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 1);
    std::uniform_int_distribution<int> dist1(0, this->maxNumberSize);
    int flag = dist(mt);

    if (flag)
        queue.enqueue(dist1(mt));
    else
        queue.dequeue(temp);
}

void Exp::testFunctionMutex(MutexQueue<int> &queue) {
    int temp;
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 1);
    std::uniform_int_distribution<int> dist1(0, this->maxNumberSize);
    int flag = dist(mt);

    if (flag)
        queue.enqueue(dist1(mt));
    else
        queue.dequeue(temp);
}
