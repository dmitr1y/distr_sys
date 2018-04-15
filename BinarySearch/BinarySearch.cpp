//
// Created by dmitriy on 15.04.18.
//

#include "BinarySearch.h"
#include <iostream>
#include <algorithm>

BinarySearch::BinarySearch(std::vector<int> array, std::vector<int> search_keys) {
    this->array = array;
    this->search_keys = search_keys;
    std::cout << "input array: ";
    this->PrintArray();
    std::cout << "input search keys: ";
    this->PrintArray(search_keys);
    this->Sort();
}

void BinarySearch::Sort() {
    std::sort(this->array.begin(), this->array.end());
}

void BinarySearch::PrintArray(std::vector<int> array) {
    for (auto _array:array) {
        std::cout << _array << ' ';
    }
    std::cout << std::endl;
}

void BinarySearch::PrintArray() {
    this->PrintArray(this->array);
}
