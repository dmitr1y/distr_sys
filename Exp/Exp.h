//
// Created by dmitriy on 06.05.18.
//

#ifndef DISTR_SYS_EXP_H
#define DISTR_SYS_EXP_H


#include <vector>
#include <thread>
#include "../MutexQueue/MutexQueue.h"
#include "../MSQueue/MSQueue.h"

class Exp {
private:
    unsigned int maxNumberSize;
    unsigned int threadsCount;
    unsigned int numberCount;
    std::vector<std::thread> threadPool;

    void testFunctionMutex(MutexQueue<int> &queue);

    void testFunctionMS(MSQueue<int> &queue);

public:
    Exp(unsigned int maxNumberSize, unsigned int numberCount, unsigned int threadsCount);

    void testMSQueue();

    void testMutex();
};


#endif //DISTR_SYS_EXP_H
