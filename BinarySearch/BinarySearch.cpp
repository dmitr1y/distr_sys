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
//    this->Sort();
    std::cout << this->isSorted(this->array) << std::endl;
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

int BinarySearch::Search(int value) {
    if (this->isSorted(this->array)) {
        std::cout << "[!] the array is sorted, so we can use binary search: " << std::endl;
        int mid = 0;
        int left = 0;
        int right = (int) (this->array.size());
        while (true) {
            mid = (left + right) / 2;

            if (value < this->array.at(mid))       // если искомое меньше значения в ячейке
                right = mid - 1;      // смещаем правую границу поиска
            else if (value > this->array.at(mid))  // если искомое больше значения в ячейке
                left = mid + 1;       // смещаем левую границу поиска
            else                       // иначе (значения равны)
//            return mid;           // функция возвращает индекс ячейки
                break;
            if (left > right)          // если границы сомкнулись
                return -1;
        }
        std::cout << "founded index: " << mid << std::endl;
    } else {
        std::cout << "[!] the array isn't sorted, so we using simple search: " << std::endl;
    }
}

bool BinarySearch::isSorted(std::vector<int> array) {
    return std::is_sorted(array.begin(), array.end());
}
