//
// Created by dmitriy on 06.05.18.
//

#ifndef DISTR_SYS_MUTEXQUEUE_H
#define DISTR_SYS_MUTEXQUEUE_H

#include <mutex>
#include <queue>
#include <iostream>

template<typename T>
class MutexQueue {

private:
    std::mutex mutex;
    std::queue<T> list;

public:
    void enqueue(const T &value);

    bool dequeue(T &value);

};

template<typename T>
void MutexQueue<T>::enqueue(const T &value) {
    std::cout << "enqueue" << std::endl;
    mutex.lock();
    list.push(value);
    mutex.unlock();
}

template<typename T>
bool MutexQueue<T>::dequeue(T &value) {
    std::cout << "dequeue" << std::endl;
    mutex.lock();

    if (list.empty()) {
        mutex.unlock();
        return false;
    }

    value = list.front();
    mutex.unlock();
    return true;
}

#endif //DISTR_SYS_MUTEXQUEUE_H
