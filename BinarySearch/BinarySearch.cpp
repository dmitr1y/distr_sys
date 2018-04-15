//
// Created by dmitriy on 15.04.18.
//

#include "BinarySearch.h"
#include <iostream>
#include <algorithm>
#include <thread>
#include <functional>

BinarySearch::BinarySearch(std::vector<int> array, std::vector<int> search_keys) {
    this->array = array;
    this->search_keys = search_keys;
    std::cout << "input array: ";
    this->PrintArray();
    std::cout << "input search keys: ";
    this->PrintArray(search_keys);
}

void BinarySearch::PrintArray(std::vector<int> array) {
    for (auto _array:array)
        std::cout << _array << ' ';
    std::cout << std::endl;
}

void BinarySearch::PrintArray() {
    this->PrintArray(this->array);
}

void BinarySearch::Search() {
    unsigned int cpuCount = GetCoresCount();
    unsigned int parts = 0;
    std::vector<std::thread> thread_pool;
    if (this->array.size() > cpuCount) {
        std::cout << "больше" << std::endl;
        parts = static_cast<unsigned int>(this->array.size() / cpuCount);
    } else if (this->array.size() == cpuCount) {
        std::cout << "равно" << std::endl;
        parts = cpuCount;
    } else {
        std::cout << "меньше" << std::endl;

        parts = static_cast<unsigned int>(cpuCount - array.size());
    }
    std::cout << "cpu count: " << cpuCount << " parts: " << parts << std::endl;

    if (this->IsSorted(this->array)) {

        std::cout << "the array is sorted, so we can use binary search: " << std::endl;

        for (int i = 0; i < this->search_keys.size(); ++i)
            thread_pool.emplace_back(&BinarySearch::BinSearch, this, 0, this->array.size(), this->search_keys.at(i));


    } else {
        std::cout << "[!] the array isn't sorted, so we using simple search: " << std::endl;
        for (int i = 0; i < cpuCount; ++i)
            thread_pool.emplace_back(&BinarySearch::SimpleSearch, this, 0, this->array.size());

    }
    for (auto &thread : thread_pool) {
        thread.join();
    }
}

bool BinarySearch::IsSorted(std::vector<int> array) {
    return std::is_sorted(array.begin(), array.end());
}

unsigned int BinarySearch::GetCoresCount() {
    return std::thread::hardware_concurrency();
}

void BinarySearch::BinSearch(unsigned int start, unsigned int end, int key) {
    unsigned int mid = 0;
    int left = start;
    int right = end;
    while (true) {
        mid = static_cast<unsigned int>((left + right) / 2);
        if (key < this->array.at(mid))
            right = mid - 1;
        else if (key > this->array.at(mid))
            left = mid + 1;
        else {
            std::cout << "index of key [" << key << "] is [" << mid << "]" << std::endl;
            break;
        }
        if (left > right)
            throw std::invalid_argument("borders closed.");
    }
}

void BinarySearch::SimpleSearch(unsigned int start, unsigned int end) {
    for (int i = start; i < end; ++i) {
        for (int search_key : this->search_keys) {
            if (this->array.at(i) == search_key)
                std::cout << "index of key [" << search_key << "] is [" << i << "]" << std::endl;
        }
    }
}
