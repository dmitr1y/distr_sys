//
// Created by dmitriy on 06.05.18.
//

#ifndef DISTR_SYS_EXP_H
#define DISTR_SYS_EXP_H


#include <vector>

class Exp {
private:
    unsigned int arraySize;
    unsigned int threadsCount;
public:
    Exp(unsigned int arraySize, unsigned int threadsCount);

    void testMSQueue();

    void testMutex();
};


#endif //DISTR_SYS_EXP_H
