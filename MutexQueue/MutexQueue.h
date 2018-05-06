//
// Created by dmitriy on 06.05.18.
//

#ifndef DISTR_SYS_MUTEXQUEUE_H
#define DISTR_SYS_MUTEXQUEUE_H

#include <mutex>
#include <queue>

template<typename T>
class MutexQueue {

private:
    std::mutex mutex;
    std::queue<T> list;

public:
    template<typename T>
    void enqueue(const T &value) {
        mutex.lock();
        list.push(value);
        mutex.unlock();
    }

    template<typename T>
    bool dequeue(T &value) {
        mutex.lock();

        if (list.empty()) {
            mutex.unlock();
            return false;
        }

        value = list.front();
        mutex.unlock();
        return true;
    }

};

#endif //DISTR_SYS_MUTEXQUEUE_H
