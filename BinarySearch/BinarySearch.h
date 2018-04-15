//
// Created by dmitriy on 15.04.18.
//

#ifndef DISTR_SYS_BINARYSEARCH_H
#define DISTR_SYS_BINARYSEARCH_H


#include <vector>

class BinarySearch {
private:
    std::vector<int> array;
    std::vector<int> search_keys;


private:
    void Sort();

    void PrintArray(std::vector<int> array);

    bool isSorted(std::vector<int> array);
public:
    BinarySearch(std::vector<int> array, std::vector<int> search_keys);

    void PrintArray();

    int Search(int value);
};


#endif //DISTR_SYS_BINARYSEARCH_H
