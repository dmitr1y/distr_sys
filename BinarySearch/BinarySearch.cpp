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
    int cpuCount = std::thread::hardware_concurrency();
    int parts = 0;

    std::vector<std::thread> thread_pool;

//    std::cout << "cpu count: " << cpuCount << std::endl;
//    int keys_size = this->search_keys.size();
    parts = (int) this->search_keys.size() / cpuCount;
    int divParts = (int) this->search_keys.size() % cpuCount;

//    std::cout << "keys_size: " << keys_size << std::endl;
//    std::cout << "parts: " << parts << " div: " << divParts << std::endl;
//    std::cout << "threads: " << parts << std::endl;

    if (this->IsSorted(this->array)) {

        std::cout << "the array is sorted, so we can use binary search: " << std::endl << std::endl;
        for (int i = 0, start = 0, end = 0; i < cpuCount && i < this->search_keys.size(); ++i) {
            end = start + parts;
            if (divParts > 0) {
                end += 1;
                divParts--;
            }
//            std::cout<<"out ["<<i<<"]"<<std::endl;
//            std::cout << "start: " << start << " end: " << end <<  std::endl;
//            std::cout << "div: " << divParts << " parts: " << parts <<  std::endl;
            std::vector<int> keys;
            for (int j = start; j < end; ++j) {
                keys.push_back(this->search_keys[j]);
            }
//            this->PrintArray(keys);
//            std::cout<<"vector size: "<<keys.size()<<std::endl;
            start = end;

            thread_pool.emplace_back(&BinarySearch::BinSearchManyKeys, this, keys);
        }


    } else {
        std::cout << "[!] the array isn't sorted, so we using simple search: " << std::endl;

        for (int i = 0, start = 0, end = 0; i < cpuCount && end < this->search_keys.size(); ++i) {
            end = start + parts;
            if (divParts > 0) {
                end += 1;
                divParts--;
            }
            std::cout << "start: " << start << " end: " << end << std::endl;
            for (int j = start; j < end; ++j) {
                thread_pool.emplace_back(&BinarySearch::BinSearch, this, 0, this->array.size(),
                                         this->search_keys.at(j));
            }
            start = end + 1;
        }
    }
    for (auto &thread : thread_pool) {
        thread.join();
    }
}

bool BinarySearch::IsSorted(std::vector<int> array) {
    return std::is_sorted(array.begin(), array.end());
}

void BinarySearch::BinSearch(unsigned int start, unsigned int end, int key) {
    unsigned int mid = 0;
    int left = start;
    int right = end;
    while (true) {
        mid = (left + right) / 2;
        if (key < this->array.at(mid))
            right = mid - 1;
        else if (key > this->array.at(mid))
            left = mid + 1;
        else {
            std::cout << "index of key [" << key << "] is [" << mid << "]" << std::endl;
            break;
        }
        if (left > right)
//            throw std::invalid_argument("borders closed.");
            break;
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

void BinarySearch::BinSearchManyKeys(std::vector<int> keys) {
    for (int i = 0; i < keys.size(); ++i) {
        this->BinSearch(0, this->array.size(), keys[i]);
    }
}
