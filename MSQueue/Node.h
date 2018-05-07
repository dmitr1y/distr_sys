//
// Created by dmitriy on 04.05.18.
//

#ifndef DISTR_SYS_NODE_H
#define DISTR_SYS_NODE_H

#include <bits/shared_ptr.h>
#include <atomic>

template<typename T>
class Node {
public:
    T data;
    std::shared_ptr<Node> next = nullptr;

    Node() {
        this->next = nullptr;
    }
};

#endif //DISTR_SYS_NODE_H
