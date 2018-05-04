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

    bool enqueue(T const &value) {
        auto node = new Node<T>;
        node->data = value;
        node->next = nullptr;

        auto last = std::atomic_load(&head);
        for (; last->next != nullptr; last = last->next) {
        }

//checking for changes in list
        auto _tail = std::atomic_load(&tail);
        if (last != _tail) {
//            if changes detected
            delete node;
            return false;
        }

    }
};

#endif //DISTR_SYS_MSQUEUE_H
