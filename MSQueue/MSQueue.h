//
// Created by dmitriy on 04.05.18.
//

#ifndef DISTR_SYS_MSQUEUE_H
#define DISTR_SYS_MSQUEUE_H

#include <bits/shared_ptr.h>
#include "Node.h"

template<typename T>
class MSQueue {
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
public:
    MSQueue() {
        this->head = this->tail = std::make_shared<Node<T>>();
    }

    void enqueue(T const &value);

    bool dequeue(T &value);
};

template<typename T>
void MSQueue<T>::enqueue(const T &value) {
    std::shared_ptr<Node<T>> node = std::make_shared<Node<T>>();
    node->data = value;
    node->next = nullptr;

    while (true) {
        auto _tail = std::atomic_load(&tail);
        // check real tail, if not - repeat action
        if (_tail->next != nullptr) {
            std::atomic_compare_exchange_weak(&tail, &_tail, tail->next);
            continue;
        }
        // if success - exit
        std::shared_ptr<Node<T>> s_null = nullptr;
        if (std::atomic_compare_exchange_weak(&_tail->next, &s_null, node)) {
            std::atomic_compare_exchange_weak(&tail, &_tail, node);
            return;
        }
    }
}

template<typename T>
bool MSQueue<T>::dequeue(T &value) {
    while (true) {
        auto _head = std::atomic_load(&head);
        auto _headNext = std::atomic_load(&head->next);
        auto _tail = std::atomic_load(&tail);

        if (std::atomic_load(&head) != _head)
            continue;

        if (_headNext == nullptr)
            return false; //empty queue, we're can't delete

        if (_head == _tail) {
            std::atomic_compare_exchange_weak(&tail, &_tail, tail->next);
            continue; //someone hadn't "incremented" tail pointer
        }

        if (std::atomic_compare_exchange_weak(&head, &_head, _headNext)) {
            value = _headNext.get()->data;
            return true;
        }
    }
}


#endif //DISTR_SYS_MSQUEUE_H
