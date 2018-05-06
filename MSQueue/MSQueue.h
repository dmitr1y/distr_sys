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
        this->head = this->tail = new Node<T>;
    }

    ~MSQueue() {
        auto node = head;
        while (node->next != nullptr) {
            auto item = node;
            node = node->next;
            delete item;
        }
    }

    void enqueue(T const &value) {
        auto node = new Node<T>;
        node->data = value;
        node->next = nullptr;

        // load tail
        while (true) {
            auto _tail = std::atomic_load(&tail);
            // check real tail
            if (_tail->next != nullptr) {
                std::atomic_compare_exchange_weak(&tail, &_tail, tail->next);
                continue;
            }
            if (std::atomic_compare_exchange_weak(&_tail->next, nullptr, &node))
                return;
        }
    }

    bool dequeue(T &value) {

    }
};

#endif //DISTR_SYS_MSQUEUE_H
