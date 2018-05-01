#include <zconf.h>
#include "MCS/mcs_lock.h"

using mySync::mcs_lock;


void func() {

    mcs_lock mcsLock;
    mcsLock.lock();
    std::cout << "sleep..." << std::endl;
    sleep(100);
    mcsLock.unlock();
    std::cout << "UNLOCKED" << std::endl;

}

int main() {

    mcs_lock mcsLock;
    std::thread thr(func);
    std::cout << "LOCKED" << std::endl;
    mcsLock.lock();
    thr.join();
    return 0;
}

