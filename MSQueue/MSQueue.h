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

        while (true) {
            auto _tail = std::atomic_load(&tail);
            // check real tail, if not - repeat action
            if (_tail->next != nullptr) {
                std::atomic_compare_exchange_weak(&tail, &_tail, tail->next);
                continue;
            }
            // if success - exit
            if (std::atomic_compare_exchange_weak(&_tail->next, nullptr, node)) {
                std::atomic_compare_exchange_weak(&tail, &_tail, node);
                return;
            }
        }
    }

    bool dequeue(T &value) {
        while (true) {
            auto _head = std::atomic_load(&head);
            auto _headNext = std::atomic_load(&head->next);
            auto _tail = std::atomic_load(&tail);

            if (_head->next == nullptr)
                return false; //empty queue, we're can't delete

            if (_head == _tail) {
                std::atomic_compare_exchange_weak(&tail, &_tail, tail->next);
                continue; //someone hadn't "incremented" tail pointer
            }

            if (std::atomic_compare_exchange_weak(&head, &_head, _headNext)) {
                value = _headNext->value;
                return true;
            }
        }
    }
};

#endif //DISTR_SYS_MSQUEUE_H
