
#include "Exp/Exp.h"

int main() {
//    max number, numbers count, threads count
//    Exp exp(10000, 1000, 5);
    Exp exp(10000, 10000000, 8);
//    exp.testMutex();
    exp.testMSQueue();
    return 0;
}